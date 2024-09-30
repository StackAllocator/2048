#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


int main(void) {

  const int SCREEN_WIDTH = 256;
  const int SCREEN_HEIGHT = 256;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not be initialized!\n"
	   "SDL_Error: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window *window = SDL_CreateWindow("2048",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH,
					SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!window)
  {
    printf("Window could not be created\n"
	   "SDL_Error: %s\n", SDL_GetError());
  }

  SDL_Rect rects[16];

  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      /*
	----
	----
	----
	----
      */
      rects[j + i * 4].x = 64 * i;
      rects[j + i * 4].y = 64 * j;

      rects[j + i * 4].w = 64;
      rects[j + i * 4].h = 64;
    }
  }

  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      /*
	----
	----
	----
	----
      */
      rects[j + i * 4].x = 64 * i;
      rects[j + i * 4].y = 64 * j;

      rects[j + i * 4].w = 64;
      rects[j + i * 4].h = 64;
    }
  }

  // Event loop exit flag
  bool quit = false;

  while (!quit)
  {
    SDL_Event event;

    SDL_WaitEvent(&event);

    if (event.type == SDL_QUIT)
    {
      quit = true;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (int i = 0; i < 16; ++i)
    {
      SDL_RenderDrawRect(renderer, &rects[i]);
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
