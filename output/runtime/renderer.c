#include <libco.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <librsvg/rsvg.h>
#include <cairo.h>
#include <math.h>
#include "types.h"
#include "../sprite_data.h"

#define RAD_TO_DEG 57.295779513082

#define FIX_X(x) ((x) / STAGE_WIDTH + 0.5) * WINDOW_WIDTH
#define FIX_Y(y) ((y) / -STAGE_HEIGHT + 0.5) * WINDOW_HEIGHT

SDL_Texture* sprite_textures[SPRITES][MAX_COSTUME_LENGTH];

int activeSprite = 1;

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteSize[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];
extern char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH];
extern double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH];
extern double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH];
extern double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH];
extern double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH];
extern int scratch_looks_CostumeIndex[];

extern double scratch_looks_effects_ghost[];

extern bool scratch_looks_hidden[];

extern SDL_Renderer* renderer;

extern cothread_t scheduler;

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

SDL_Texture* GetPNGSprite(char* name, int* width_out, int* height_out) 
{
	char* path = "../../../../scratch/Project/";

	char* srtc = malloc(strlen(name) + strlen(path) + 1);
	if (!srtc) { printf("Malloc error!"); exit(-1); }

	strcpy(srtc, path);

	strcat(srtc, name);

	SDL_Surface* surface = IMG_Load(srtc);
	if (!surface) 
	{
		printf("Could not load image %s.\n", srtc);
		exit(-1);
	}

	free(srtc);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	*width_out  = surface->w / 2;
	*height_out = surface->h / 2;

	SDL_FreeSurface(surface);

	return texture;
}

SDL_Texture* GetSVGSprite(char* name, int* width_out, int* height_out) 
{
	int width = 256;
	int height = 256;

	GError* err = NULL;

	char* this = name;

	if (!this)
	{
		return NULL;
	}

	char* path = "../../../../scratch/Project/";

	char* srtc = malloc(strlen(this) + strlen(path) + 1);
	if (!srtc) { printf("Malloc error!"); exit(-1); }

	strcpy(srtc, path);

	strcat(srtc, this);

	//if()

	RsvgHandle* handle = rsvg_handle_new_from_file(srtc, &err);
	if (!handle) {
		fprintf(stderr, "Error loading SVG: %s\n", err->message);
		return sprite_textures[0][0];
		//exit(-1);
	}

	free(srtc);

	RsvgDimensionData dim;
	rsvg_handle_get_dimensions(handle, &dim);

	if (dim.width == 0 || dim.height == 0) {
		fprintf(stderr, "SVG has invalid dimensions\n");
		g_object_unref(handle);
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		width,
		height
	);

	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);


	if (!tex) {
		fprintf(stderr, "SDL_CreateTexture failed: %s\n", SDL_GetError());
		g_object_unref(handle);
		return NULL;
	}

	uint32_t* pixels;
	int pitch;

	if (SDL_LockTexture(tex, NULL, (void**)&pixels, &pitch) != 0) {
		fprintf(stderr, "SDL_LockTexture failed: %s\n", SDL_GetError());
		SDL_DestroyTexture(tex);
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

	double scaled_w = dim.width  * (double)width  /  dim.width;
	double scaled_h = dim.height * (double)height / dim.height;

	*width_out  = dim. width;
	*height_out = dim.height;

	double dx = (width - scaled_w) / 2.0;
	double dy = (height - scaled_h) / 2.0;

	cairo_translate(cr, dx, dy);
	cairo_scale(cr, (double)width / dim.width, (double)height / dim.height);


	if (!rsvg_handle_render_cairo(handle, cr)) {
		fprintf(stderr, "Failed to render SVG\n");
		cairo_destroy(cr);
		cairo_surface_destroy(surface);
		SDL_UnlockTexture(tex);
		SDL_DestroyTexture(tex);
		g_object_unref(handle);
		return NULL;
	}

	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	SDL_UnlockTexture(tex);
	g_object_unref(handle);

	return tex;
}

void initRenderer()
{
	for (int i = 0; i < SPRITES; i++) 
	{
		for (int j = 0; j < MAX_COSTUME_LENGTH; j++) 
		{
			int width = 0, height = 0;
			if (scratch_looks_CostumeFiles[i][j] == NULL) 
			{
				continue;
			}
			char c = scratch_looks_CostumeFiles[i][j][strlen(scratch_looks_CostumeFiles[i][j]) - 2];
			if (c == 'n') 
			{
				sprite_textures[i][j] = GetPNGSprite(scratch_looks_CostumeFiles[i][j], &width, &height);
			}
			else
			{
				sprite_textures[i][j] = GetSVGSprite(scratch_looks_CostumeFiles[i][j], &width, &height);
			}
			scratch_motion_SpriteWidth [i][j] =  width;
			scratch_motion_SpriteHeight[i][j] = height;
		}
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
	if (a == 0) { a = 255; }

	if (x_1 == x_2 && y_1 != y_2)
	{
		SDL_Rect rect;
		rect.x = x1;
		rect.y = min(y1,y2);
		rect.w = t * 2;
		rect.h = fabsf(y2 - y1);

		SDL_SetRenderDrawColor(renderer, r, g, b, a);

		SDL_RenderFillRect(renderer, &rect);
	}
	else 
	{
		if (!(x_1 == x_2 && y_1 == y_2))
		{
			SDL_Vertex verts[4] = {
				{ { x1 + nx, y1 + ny }, {r, g, b, a}, {0, 0} },
				{ { x1 - nx, y1 - ny }, {r, g, b, a}, {0, 0} },
				{ { x2 - nx, y2 - ny }, {r, g, b, a}, {0, 0} },
				{ { x2 + nx, y2 + ny }, {r, g, b, a}, {0, 0} }
			};

			int indices[6] = { 0, 1, 2, 0, 2, 3 };

			SDL_RenderGeometry(renderer, NULL, verts, 4, indices, 6);
			filledCircleRGBA(renderer, x1, y1, t / 2, r, g, b, a);
		}

		filledCircleRGBA(renderer, x2, y2, t / 2, r, g, b, a);
	}
}

void DrawSprite(double x, double y, double size, double direction, double width2, double height2, int rotstyle, int sprite, int costume, double ghost_effect) 
{
	SDL_Rect rect;

	double scale = size * (WINDOW_WIDTH / (double)STAGE_WIDTH / 100);

	int width = width2 * scale;
	int height = height2 * scale;

	double x_fixed = FIX_X(x);
	double y_fixed = FIX_Y(y);

	SDL_Point centre = { (scratch_looks_RotationCentreX[sprite][costume]) * (WINDOW_WIDTH / (double)STAGE_WIDTH) * (size / 100.0), (scratch_looks_RotationCentreY[sprite][costume]) * (WINDOW_HEIGHT / (double)STAGE_HEIGHT) * (size / 100.0) };

	rect.x = x_fixed - centre.x;
	rect.y = y_fixed - centre.y;
	rect.w = width;
	rect.h = height;

	SDL_SetTextureAlphaMod(sprite_textures[sprite][costume], (100 - min(max(ghost_effect,0),100)) * 2.55);

	switch (rotstyle)
	{
	case RotStyle_allaround:
		SDL_RenderCopyEx(renderer, sprite_textures[sprite][costume], NULL, &rect, direction * RAD_TO_DEG, &centre, SDL_FLIP_NONE);
		break;
	case RotStyle_dontrotate:
		SDL_RenderCopy(renderer, sprite_textures[sprite][costume], &centre, &rect);
		break;
	case RotStyle_leftright:
		printf("%f\n", fmod(direction * RAD_TO_DEG, 360.0));
		if (fmod(direction * RAD_TO_DEG, 360.0) > 180)
		{
			SDL_RenderCopyEx(renderer, sprite_textures[sprite][costume], NULL, &rect, 0, &centre, SDL_FLIP_NONE);
		}
		else
		{
			SDL_RenderCopyEx(renderer, sprite_textures[sprite][costume], NULL, &rect, 0, &centre, SDL_FLIP_HORIZONTAL);
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

		DrawSprite(sd.x, sd.y, sd.size, sd.rotation, sd.width, sd.height, sd.rot_style, sd.sprite_index, sd.costume_index, sd.ghost_effect);
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
			int width = 0, height = 0;
			DrawSprite(scratch_motion_SpriteX[i], scratch_motion_SpriteY[i], scratch_motion_SpriteSize[i], scratch_motion_SpriteDirection[i],
				scratch_motion_SpriteWidth[i][scratch_looks_CostumeIndex[i]],
				scratch_motion_SpriteHeight[i][scratch_looks_CostumeIndex[i]],
				scratch_motion_SpriteRotStyle[i], i, scratch_looks_CostumeIndex[i],
				scratch_looks_effects_ghost[i]);
		}
	}
}