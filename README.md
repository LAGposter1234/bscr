# BSCR — Basic Sandboxed C Runtime

A minimal C runtime that provides a 512MiB memory sandbox and an SDL2-backed framebuffer. Write your "OS" in `program.h` and it runs directly against the memory.

## How It Works

BSCR allocates a flat 512MiB memory array and passes it to your program. The last 1,440,000 bytes are mapped to an 800x600 24bpp SDL2 framebuffer — write pixels there and they show up on screen. Everything below that is free RAM for your program to use however it wants.

## Building

Requires `gcc` and SDL2.
```bash
gcc src/main.c -o bscr -lSDL2
```

## Usage

Write your program in `src/program.h` as a function:
```c
void program(uint8_t *mem) {
    // your code here
}
```

Then build and run:
```bash
./bscr
```

To draw a pixel at (x, y) with color (r, g, b):
```c
#define FB (mem + 512*1024*1024 - 800*600*3)
#define PIXEL(x, y, r, g, b) \
    FB[((y)*800+(x))*3+0] = r; \
    FB[((y)*800+(x))*3+1] = g; \
    FB[((y)*800+(x))*3+2] = b;
```
