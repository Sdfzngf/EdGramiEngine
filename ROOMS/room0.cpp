#include <SDL3/SDL.h>
#include <SDL3/SDL_thread.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include <string>
extern bool ldfail;
extern std::string Task;
extern SDL_Renderer* renderer;
void room0() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_SetRenderScale(renderer, 1.0f, 1.0f);
	SDL_RenderDebugText(renderer, 0, 470, ("task:" + Task).c_str());
	SDL_SetRenderScale(renderer, 4.0f, 4.0f);
	SDL_RenderDebugText(renderer, 45, 52, "加Loading载");
	if (ldfail) {
		SDL_SetRenderScale(renderer, 2.0f, 2.0f);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDebugText(renderer, 107, 130, "Failed to load");
	}
}