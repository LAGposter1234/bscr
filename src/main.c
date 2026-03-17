#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MEM_SIZE (512 * 1024 * 1024)
#define FB_OFFSET (MEM_SIZE - WIDTH * HEIGHT * 3)

#include "program.h"

int main() {
	uint8_t *mem = malloc(MEM_SIZE);

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *win = SDL_CreateWindow("bscr", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
	SDL_Texture *tex = SDL_CreateTexture(ren, NULL, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

	program(mem);

	SDL_Event e;
	int running = 1;
	while (running) {
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT) running = 0;

		SDL_UpdateTexture(tex, NULL, mem + FB_OFFSET, WIDTH * 3);
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderPresent(ren);
	}

	free(mem);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
