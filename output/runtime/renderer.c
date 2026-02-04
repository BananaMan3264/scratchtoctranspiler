#include <SDL2/SDL.h>
#include <librsvg/rsvg.h>
#include <cairo.h>
#include <math.h>
#include"types.h"
#include"../data.h"

#define RAD_TO_DEG 57.295779513082

SDL_Texture* sprite_textures[SPRITES];

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteSize[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];

extern bool scratch_looks_hidden[];

extern SDL_Renderer* renderer;

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

		RsvgHandle* handle = rsvg_handle_new_from_file("../../../../scratch/Project/927d672925e7b99f7813735c484c6922.svg", &err);
		if (!handle) {
			fprintf(stderr, "Error loading SVG: %s\n", err->message);
			return NULL;
		}

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

		double scaled_w = dim.width * s;
		double scaled_h = dim.height * s;

		double dx = (width - scaled_w) / 2.0;
		double dy = (height - scaled_h) / 2.0;

		cairo_translate(cr, dx, dy);
		cairo_scale(cr, s, s);


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

void draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_Rect rect;


	for (int i = 0; i < SPRITES; i++)
	{
		int width = scratch_motion_SpriteSize[i] * (WINDOW_WIDTH / (double)STAGE_WIDTH);
		int height = width;

		rect.x = (scratch_motion_SpriteX[i] /  480 + 0.5) * WINDOW_WIDTH  - width  / 2;
		rect.y = (scratch_motion_SpriteY[i] / -360 + 0.5) * WINDOW_HEIGHT - height / 2;
		rect.w = width;
		rect.h = height;

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		if (!scratch_looks_hidden[i])
		{
			switch (scratch_motion_SpriteRotStyle[i])
			{
			case RotStyle_allaround:
				SDL_RenderCopyEx(renderer, sprite_textures[i], NULL, &rect, scratch_motion_SpriteDirection[i] * RAD_TO_DEG, NULL, SDL_FLIP_NONE);
				break;
			case RotStyle_dontrotate:
				SDL_RenderCopy(renderer, sprite_textures[i], NULL, &rect);
				break;
			case RotStyle_leftright:
				printf("%f\n", fmod(scratch_motion_SpriteDirection[i] * RAD_TO_DEG, 360.0));
				if (fmod(scratch_motion_SpriteDirection[i] * RAD_TO_DEG, 360.0) > 180)
				{
					SDL_RenderCopyEx(renderer, sprite_textures[i], NULL, &rect, 0, NULL, SDL_FLIP_NONE);
				}
				else 
				{
					SDL_RenderCopyEx(renderer, sprite_textures[i], NULL, &rect, 0, NULL, SDL_FLIP_HORIZONTAL);
				}
				//TODO: This
				break;
			}

			SDL_RenderDrawRect(renderer, &rect);
		}
	}
}