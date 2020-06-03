#include <SDL2/SDL.h>
#include <string>
#include <iostream>

#include "ball.hpp"

SDL_Window* window;
SDL_Renderer* renderer;
const int ScreenWidth = 640;
const int ScreenHeight = 480;
Ball* ball = nullptr;

void render() {

	SDL_Rect ballDstRect = {
		ball->x,
		ball->y,
		ball->w,
		ball->h
	}; // This is the Ball Destination Rect

	// Set The Color to White, To render the ball
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &ballDstRect);
}
int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING); // Initialise the SDL2 Context

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Event e;
	ball = new Ball(20, 20, 15, 15);

	Uint32 CurrentFrame, FrameTime;
	const int FPS = 30;
	const int FrameDelay = 1000 / FPS;
	
	while (true) {
		CurrentFrame = SDL_GetTicks();

		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT)
			break;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		render();
		SDL_RenderPresent(renderer);

		FrameTime = SDL_GetTicks() - CurrentFrame;
		if (FrameDelay > FrameTime)
			SDL_Delay(FrameDelay - FrameTime);
	}

	delete ball; // De-Allocate the Memory
	return 0;
}