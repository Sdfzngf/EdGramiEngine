#include <SDL3/SDL_thread.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
extern SDL_Renderer* renderer;
extern int drtxmd;
void RenderText_Blended(const char* text, TTF_Font* font, int r, int g, int b, float x, float y) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Blended(font, text, strlen(text), Color_BLK);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText_Shaded(const char* text, TTF_Font* font, int r, int g, int b, float x, float y) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_Color COLOR_BG = { 0,0,0,0 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Shaded(font, text, strlen(text), Color_BLK, COLOR_BG);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText_Solid(const char* text, TTF_Font* font, int r, int g, int b, float x, float y) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Solid(font, text, strlen(text), Color_BLK);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText(const char* text, TTF_Font* font, int r, int g, int b, float x, float y) {
	SDL_SetRenderScale(renderer, 1.0f, 1.0f);
	if (drtxmd == 2) {
		RenderText_Solid(text, font, r, g, b, x, y);
	}
	else if (drtxmd == 1) {
		RenderText_Shaded(text, font, r, g, b, x, y);
	}
	else {
		RenderText_Blended(text, font, r, g, b, x, y);
	}
}
void RenderText_Blended_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y,int wraplength) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Blended_Wrapped(font, text, strlen(text), Color_BLK,wraplength);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText_Shaded_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y,int wraplength) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_Color COLOR_BG = { 0,0,0,0 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Shaded_Wrapped(font, text, strlen(text), Color_BLK, COLOR_BG,wraplength);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText_Solid_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y,int wraplength) {
	SDL_Color Color_BLK = { r,g,b,255 };
	SDL_FRect dstrect;
	SDL_Surface* sfce = TTF_RenderText_Solid_Wrapped(font, text, strlen(text), Color_BLK,wraplength);
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = sfce->w;
	dstrect.h = sfce->h;
	SDL_Texture* textu = SDL_CreateTextureFromSurface(renderer, sfce);
	SDL_RenderTexture(renderer, textu, nullptr, &dstrect);
	SDL_DestroyTexture(textu);
	SDL_DestroySurface(sfce);
}
void RenderText_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y,int wraplength) {
	SDL_SetRenderScale(renderer, 1.0f, 1.0f);
	if (drtxmd == 2) {
		RenderText_Solid_Wrapped(text, font, r, g, b, x, y,wraplength);
	}
	else if (drtxmd == 1) {
		RenderText_Shaded_Wrapped(text, font, r, g, b, x, y,wraplength);
	}
	else {
		RenderText_Blended_Wrapped(text, font, r, g, b, x, y,wraplength);
	}
}