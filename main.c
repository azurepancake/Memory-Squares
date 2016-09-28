#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect squareOne;
SDL_Rect squareTwo;
SDL_Rect squareThree;
SDL_Rect squareFour;

void init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Memory Squares", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 230, 230, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void renderSquares()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	squareOne.x = 10;
	squareOne.y = 10;
	squareOne.w = 100;
	squareOne.h = 100;
	SDL_SetRenderDrawColor(renderer, 0, 50, 0, 255);
	SDL_RenderFillRect(renderer, &squareOne);

	squareTwo.x = 10;
	squareTwo.y = 120;
	squareTwo.w = 100;
	squareTwo.h = 100;
	SDL_SetRenderDrawColor(renderer, 50, 50, 0, 255);
	SDL_RenderFillRect(renderer, &squareTwo);

	squareThree.x = 120;
	squareThree.y = 10;
	squareThree.w = 100;
	squareThree.h = 100;
	SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);

	squareFour.x = 120;
	squareFour.y = 120;
	squareFour.w = 100;
	squareFour.h = 100;
	SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
	SDL_RenderFillRect(renderer, &squareFour);

	SDL_RenderPresent(renderer);
}

void bye()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int events(SDL_Event e)
{
	int mouseX;
	int mouseY;

	while(SDL_PollEvent(&e) != 0) {
		if(e.type == SDL_QUIT) {
			return 5;
		}
		
		if(e.type == SDL_MOUSEBUTTONUP) {
			if(e.button.button == SDL_BUTTON_LEFT) {
				SDL_SetRenderDrawColor(renderer, 0, 50, 0, 255);
				SDL_RenderFillRect(renderer, &squareOne);
				SDL_SetRenderDrawColor(renderer, 50, 50, 0, 255);
				SDL_RenderFillRect(renderer, &squareTwo);
				SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
				SDL_RenderFillRect(renderer, &squareThree);
				SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
				SDL_RenderFillRect(renderer, &squareFour);
				SDL_RenderPresent(renderer);
			}
		}

		if(e.type == SDL_MOUSEBUTTONDOWN && mouseX >= 10 && mouseX <= 110 && mouseY >= 10 && mouseY <= 110) {
			if(e.button.button == SDL_BUTTON_LEFT) {
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Green box clicked!", window);
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
				SDL_RenderFillRect(renderer, &squareOne);
				SDL_RenderPresent(renderer);

				return 1;
			}
		}
		else if(e.type == SDL_MOUSEBUTTONDOWN && mouseX >= 10 && mouseX <= 110 && mouseY >= 120 && mouseY <= 220) {
			if(e.button.button == SDL_BUTTON_LEFT) {
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Yellow box clicked!", window);
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
				SDL_RenderFillRect(renderer, &squareTwo);
				SDL_RenderPresent(renderer);

				return 2;
			}
		}
		else if(e.type == SDL_MOUSEBUTTONDOWN && mouseX >= 120 && mouseX <= 220 && mouseY >= 10 && mouseY <= 110) {
			if(e.button.button == SDL_BUTTON_LEFT) {
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Red box clicked!", window);
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &squareThree);
				SDL_RenderPresent(renderer);

				return 3;
			}
		}
		else if(e.type == SDL_MOUSEBUTTONDOWN && mouseX >= 120 && mouseX <= 220 && mouseY >= 120 && mouseY <= 220) {
			if(e.button.button == SDL_BUTTON_LEFT) {
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Blue box clicked!", window);
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderFillRect(renderer, &squareFour);
				SDL_RenderPresent(renderer);

				return 4;
			}
		}

		if(e.type == SDL_MOUSEMOTION) {
			mouseX = e.motion.x;
			mouseY = e.motion.y;
		}
	} 
	
	return 0;
}

void playPattern() {
	SDL_SetRenderDrawColor(renderer, 0, 50, 0, 255);
	SDL_RenderFillRect(renderer, &squareOne);
	SDL_SetRenderDrawColor(renderer, 50, 50, 0, 255);
	SDL_RenderFillRect(renderer, &squareTwo);
	SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);
	SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
	SDL_RenderFillRect(renderer, &squareFour);
	SDL_RenderPresent(renderer);

	SDL_Delay(1000);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &squareTwo);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 50, 50, 0, 255);
	SDL_RenderFillRect(renderer, &squareTwo);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
	SDL_RenderFillRect(renderer, &squareThree);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &squareFour);
	SDL_RenderPresent(renderer);

	SDL_Delay(250);

	SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
	SDL_RenderFillRect(renderer, &squareFour);
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
	init();
	renderSquares();

	SDL_Event e;
	int score = 0;
	int roundOne[4] = {2, 3, 3, 4};

	while(1) {
		playPattern();

		int i = 0;
		int selection;
		
		for(i = 0; i <= 3; i++) {
			selection = 0;

			while(selection == 0) {
				selection = events(e);
			}

			if(selection == roundOne[i]) {
				score++;
				
				if(score == 4) {
					SDL_ShowSimpleMessageBox(0, "Correct!", "Good job!", window);
				}
			}
			else if(selection == 5) {
				break;
			}
			else {
				SDL_ShowSimpleMessageBox(0, "Wrong!", "Incorrect! Start over..", window);
				break;
			}
		}

		if(selection == 5) {
			break;			
		}
	}

	bye();

	return 0;
}
