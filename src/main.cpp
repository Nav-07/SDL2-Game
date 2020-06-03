#include <SDL2/SDL.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
	SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Event e;
	while (true) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT)
			break;

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	return 0;
}