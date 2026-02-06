#include <SDL2/SDL.h>
#include <librsvg/rsvg.h>
#include <cairo.h>
#include <math.h>
#include "types.h"
#include "../sprite_data.h"

#define RAD_TO_DEG 57.295779513082

#define FIX_X(x) ((x) / STAGE_WIDTH + 0.5) * WINDOW_WIDTH
#define FIX_Y(y) ((y) / -STAGE_HEIGHT + 0.5) * WINDOW_HEIGHT

SDL_Texture* sprite_textures[SPRITES];

int activeSprite = 1;

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteSize[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];
extern char* scratch_looks_CostumeFiles[];
extern int scratch_motion_SpriteWidth[];
extern int scratch_motion_SpriteHeight[];

extern bool scratch_looks_hidden[];

extern SDL_Renderer* renderer;

extern PenOperations ops;

/*
According to my research the Scratch VM refreshed the screen:
- At each iteration of all repeat, repeat until, while, and forever loops
- After each 'glide' block
- After each say/think for seconds block
- After each  `play sound <> until done`, but only if an actual sound is provided
- After each `wait <> seconds`
- After each `Wait until`
- After each `ask <> and wait`
*/

void initRenderer()
{
	for (int i = 0; i < SPRITES; i++) 
	{
		int width = 2048;
		int height = 2048;

		GError* err = NULL;

		char* this = scratch_looks_CostumeFiles[i];

		char* path = "../../../../scratch/Project/";

		char* srtc = malloc(strlen(this) + strlen(path) + 1); 
		if (!srtc) { printf("Malloc error!"); exit(-1); }

		strcpy(srtc, path);

		strcat(srtc, this);

		RsvgHandle* handle = rsvg_handle_new_from_file(srtc, &err);
		if (!handle) {
			fprintf(stderr, "Error loading SVG: %s\n", err->message);
			exit(-1);
		}

		free(srtc);

		RsvgDimensionData dim;
		rsvg_handle_get_dimensions(handle, &dim);

		if (dim.width == 0 || dim.height == 0) {
			fprintf(stderr, "SVG has invalid dimensions\n");
			g_object_unref(handle);
			return NULL;
		}

		sprite_textures[i] = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			width,
			height
		);

		SDL_SetTextureBlendMode(sprite_textures[i], SDL_BLENDMODE_BLEND);


		if (!sprite_textures[i]) {
			fprintf(stderr, "SDL_CreateTexture failed: %s\n", SDL_GetError());
			g_object_unref(handle);
			return NULL;
		}

		uint32_t* pixels;
		int pitch;

		if (SDL_LockTexture(sprite_textures[i], NULL, (void**)&pixels, &pitch) != 0) {
			fprintf(stderr, "SDL_LockTexture failed: %s\n", SDL_GetError());
			SDL_DestroyTexture(sprite_textures[i]);
			g_object_unref(handle);
			return NULL;
		}

		cairo_surface_t* surface = cairo_image_surface_create_for_data(
			(unsigned char*)pixels,
			CAIRO_FORMAT_ARGB32,
			width,
			height,
			pitch
		);

		cairo_t* cr = cairo_create(surface);

		cairo_set_source_rgba(cr, 0, 0, 0, 0);
		cairo_paint(cr);

		double maxdim = (dim.width > dim.height) ? dim.width : dim.height;
		double s = (double)width / maxdim;   // same for height since it's square

		double scaled_w = dim.width * (double)width / dim.width;
		double scaled_h = dim.height * (double)height / dim.height;

		scratch_motion_SpriteWidth[i] = dim.width;
		scratch_motion_SpriteHeight[i] = dim.height;

		double dx = (width - scaled_w) / 2.0;
		double dy = (height - scaled_h) / 2.0;

		cairo_translate(cr, dx, dy);
		cairo_scale(cr, (double)width / dim.width, (double)height / dim.height);


		if (!rsvg_handle_render_cairo(handle, cr)) {
			fprintf(stderr, "Failed to render SVG\n");
			cairo_destroy(cr);
			cairo_surface_destroy(surface);
			SDL_UnlockTexture(sprite_textures[i]);
			SDL_DestroyTexture(sprite_textures[i]);
			g_object_unref(handle);
			return NULL;
		}

		cairo_destroy(cr);
		cairo_surface_destroy(surface);

		SDL_UnlockTexture(sprite_textures[i]);
		g_object_unref(handle);

	}
}

void DrawLine(float x_1, float y_1, float x_2, float y_2, float thickness, int colour)
{
	float x1 = FIX_X(x_1), y1 = FIX_Y(y_1), x2 = FIX_X(x_2), y2 = FIX_Y(y_2), t = thickness * (WINDOW_WIDTH / (double)STAGE_WIDTH);
	float dx = x2 - x1;
	float dy = y2 - y1;
	float length = sqrtf(dx * dx + dy * dy);

	float nx = -dy / length * (t / 2);
	float ny = dx / length * (t / 2);

	unsigned char b = (colour & 0x000000ff) >>  0;
	unsigned char g = (colour & 0x0000ff00) >>  8;
	unsigned char r = (colour & 0x00ff0000) >> 16;
	unsigned char a = (colour & 0xff000000) >> 24;

	SDL_Vertex verts[4] = {
		{ { x1 + nx, y1 + ny }, {r, g, b, a}, {0, 0} },
		{ { x1 - nx, y1 - ny }, {r, g, b, a}, {0, 0} },
		{ { x2 - nx, y2 - ny }, {r, g, b, a}, {0, 0} },
		{ { x2 + nx, y2 + ny }, {r, g, b, a}, {0, 0} }
	};

	int indices[6] = { 0, 1, 2, 0, 2, 3 };

	SDL_RenderGeometry(renderer, NULL, verts, 4, indices, 6);

}

void DrawSprite(double x, double y, double size, double direction, double width2, double height2, int rotstyle, int texture_index) 
{
	SDL_Rect rect;

	double scale = size * (WINDOW_WIDTH / (double)STAGE_WIDTH / 100);

	int width = width2 * scale;
	int height = height2 * scale;

	rect.x = FIX_X(x) - width / 2;
	rect.y = FIX_Y(y) - height / 2;
	rect.w = width;
	rect.h = height;

	switch (rotstyle)
	{
	case RotStyle_allaround:
		SDL_RenderCopyEx(renderer, sprite_textures[texture_index], NULL, &rect, direction * RAD_TO_DEG, NULL, SDL_FLIP_NONE);
		break;
	case RotStyle_dontrotate:
		SDL_RenderCopy(renderer, sprite_textures[texture_index], NULL, &rect);
		break;
	case RotStyle_leftright:
		printf("%f\n", fmod(direction * RAD_TO_DEG, 360.0));
		if (fmod(direction * RAD_TO_DEG, 360.0) > 180)
		{
			SDL_RenderCopyEx(renderer, sprite_textures[texture_index], NULL, &rect, 0, NULL, SDL_FLIP_NONE);
		}
		else
		{
			SDL_RenderCopyEx(renderer, sprite_textures[texture_index], NULL, &rect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		//TODO: This
		break;
	}
}

void DrawPenOp(PenOperation po) 
{
	if (po.operation_type == Pen_Line) 
	{
#define P po.operation_data.line_data
		DrawLine(P.x1, P.y1, P.x2, P.y2, P.thickness, P.colour);
#undef P
	}
	else 
	{
		stampData sd = po.operation_data.stamp_data;

		DrawSprite(sd.x, sd.y, sd.size, sd.rotation, sd.width, sd.height, sd.rot_style, sd.sprite_index);
	}
}

void draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	for (int i = 0; i < ops.length; i++) 
	{
		DrawPenOp(ops.data[i]);
	}

	for (int i = 0; i < SPRITES; i++)
	{

		if (!scratch_looks_hidden[i])
		{
			DrawSprite(scratch_motion_SpriteX[i], scratch_motion_SpriteY[i], scratch_motion_SpriteSize[i], scratch_motion_SpriteDirection[i], scratch_motion_SpriteWidth[i],
				scratch_motion_SpriteHeight[i], scratch_motion_SpriteRotStyle[i], i);
		}
	}
}