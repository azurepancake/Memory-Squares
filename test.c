#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect squareOne;
SDL_Rect squareTwo;

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 300, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	squareOne.x = 10;
	squareOne.y = 10;
	squareOne.w = 100;
	squareOne.h = 100;

	SDL_SetRenderDrawColor(renderer, 0, 50, 0, 0);
	SDL_RenderFillRect(renderer, &squareOne);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);

	squareTwo.x = 10;
	squareTwo.y = 120;
	squareTwo.w = 100;
	squareTwo.h = 100;
	SDL_SetRenderDrawColor(renderer, 50, 50, 0, 0);
	SDL_RenderFillRect(renderer, &squareTwo);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
