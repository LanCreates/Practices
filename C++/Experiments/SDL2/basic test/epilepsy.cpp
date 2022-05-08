#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#define RGB(surf, r, g, b) SDL_MapRGB(surf->format, r, g, b)

const int SCR_WIDTH = 500;
const int SCR_HEIGHT = 500;

class point {
	SDL_Rect rect;

	public:
		int Xpos = 0;
		int Ypos = 0;
		
		point(short width, short height) {
			rect.w = width;
			rect.h = height;
		}

		int getSize(char code) {
			return code == 'w'? rect.w: rect.h;
		}

		void setColor(SDL_Renderer* renderer, short red, short green, short blue) {
			SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
		}
		
		void renderInPosition(SDL_Renderer* renderer) {
			rect.x = Xpos;
			rect.y = Ypos;
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderPresent(renderer);
		}
};

int main_loop(SDL_Window* win) {
	SDL_Event event;
	SDL_Surface* surface = SDL_GetWindowSurface(win);
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);

	point cube(50, 50);
	SDL_Color bg {0, 0, 0, 255};
	SDL_Color rectColo {0, 0, 0, 255};
	SDL_Rect trail1 {0, 0, 50, 50};
	SDL_Rect trail2 {0, 0, 50, 50};
	
	std::vector<std::vector<int>> posHistory {};

	bool done = false;
	short clicks = 0;
	while(!done) {
		bool moved = false;
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT) {
			done = true;
		} else if(event.type == SDL_KEYDOWN) {
			switch(event.key.keysym.sym) {
				case SDLK_d:
					clicks++;
					break;
				case SDLK_a:
					clicks--;
					break;
				case SDLK_UP:
					moved = true;
					if(cube.Ypos > 0) {
						cube.Ypos -= 10;
					} break;
				case SDLK_DOWN:
					moved = true;
					if(cube.Ypos < SCR_HEIGHT - cube.getSize('h')) {
						cube.Ypos += 10;
					} break;
				case SDLK_RIGHT:
					moved = true;
					if(cube.Xpos < SCR_WIDTH - cube.getSize('w')) {
						cube.Xpos += 10;
					} break;
				case SDLK_LEFT:
					moved = true;
					if(cube.Xpos > 0) {
					cube.Xpos -= 10;
					} break;
			}
		}
		
		switch(clicks % 3) {
			case 0: bg = {0, 0, 255, 255}; break;
			case 1: bg = {0, 255, 0, 255}; break;
			case 2: bg = {255, 0, 0, 255}; break;
		}

		SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
		SDL_RenderClear(renderer);
		
		if(moved) {
			if(posHistory.size() < 3) {
				posHistory.push_back({cube.Xpos, cube.Ypos});
				if(posHistory.size() == 1) {
					trail1 = {posHistory[0][0], posHistory[0][1],
							trail1.w, trail1.h};
				}
			} else {
				posHistory[0] = posHistory[1];
				posHistory[1] = posHistory[2];
				posHistory[2] = {cube.Xpos, cube.Ypos};
			}

			if(posHistory.size() > 1) {
				trail1 = {posHistory[1][0], posHistory[1][1],
						trail1.w, trail1.h};
				trail2 = {posHistory[0][0], posHistory[0][1],
						trail2.w, trail2.h};
			}
		}

		switch(clicks % 3) {
			case 0: rectColo = {255, 0, 0, 255}; break;
			case 1: rectColo = {0, 0, 255, 255}; break;
			case 2: rectColo = {0, 255, 0, 255}; break;
		}
		SDL_SetRenderDrawColor(renderer, rectColo.r/4, rectColo.g/4, rectColo.b/4, rectColo.a);
		SDL_RenderFillRect(renderer, &trail2);
		SDL_SetRenderDrawColor(renderer, rectColo.r/2, rectColo.g/2, rectColo.b/2, rectColo.a);
		SDL_RenderFillRect(renderer, &trail1);

		cube.setColor(renderer, rectColo.r, rectColo.g, rectColo.b);
		cube.renderInPosition(renderer);
		clicks++;
		clicks = clicks == 3? 0: (clicks < 0? 2: clicks);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL initialization failed\n%s\n", SDL_GetError());
		return 0;
	}
	
	// Declare the window and screen
	SDL_Window* window = SDL_CreateWindow("Yourvisionus Deletus",
						SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
						SCR_WIDTH, SCR_HEIGHT, 
						SDL_WINDOW_SHOWN);
	if(window == NULL) {
		printf("SDL window initialization failed\n%s\n", SDL_GetError());
		return 0;
	}
	
	int flag = main_loop(window);
	if(flag < 0) {
		printf("Unexpected failure happened");
		return 0;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
