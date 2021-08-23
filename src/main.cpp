#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;


int main(int argc, char* argv[])
{

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL failed to initialize. SDL Error: " << SDL_GetError() << std::endl; 
        return EXIT_FAILURE;
    }
    
    SDL_Window* window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(nullptr == window){
        std::cout << "SDL failed to create window. SDL Error: " << SDL_GetError() << std::endl; 
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event e;
    while( true){
        if(SDL_PollEvent(&e)){
            if (SDL_QUIT == e.type){
                break;
            }
        }
        SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderPresent(renderer);
    }

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    
    return EXIT_SUCCESS;
}

