#pragma once
#include "SDL3_ttf/SDL_ttf.h"
void RenderText_Blended(const char* text, TTF_Font* font, int r, int g, int b, float x, float y);
void RenderText_Shaded(const char* text, TTF_Font* font, int r, int g, int b, float x, float y);
void RenderText_Solid(const char* text, TTF_Font* font, int r, int g, int b, float x, float y);
void RenderText(const char* text, TTF_Font* font, int r, int g, int b, float x, float y);
void RenderText_Blended_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y,int wraplength);
void RenderText_Shaded_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y, int wraplength);
void RenderText_Solid_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y, int wraplength);
void RenderText_Wrapped(const char* text, TTF_Font* font, int r, int g, int b, float x, float y, int wraplength);