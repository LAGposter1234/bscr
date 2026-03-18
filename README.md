# READ ME!

BSCR stands for Basic Sandboxed C Runtime, and its basically like the average C emulator, exept replace the input .bin file with an included C source.


## HOW TO COMPILE!

Make sure you are in repo-root/ (not actual folder name, example) and run this command

```bash
gcc src/main.c -o bin/out -lSDL2
```

You will need SDL2 for this. Install like this

### Fedora

```bash
sudo dnf install SDL2-devel
```

### Ubuntu base

```bash
sudo apt install SDL2-devel
```

### Arch base

```
sudo pacman install SDL2-devel
```

Dont worry, you dont have to compile program.h.

## HOW TO WRITE CODE FOR THIS!

You can write code by editing the program.h file.
Your program needs an init(uint8_t* mem) function and an update(uint8_t* mem) function.
It is also recommended to make draw, drawtext, drawrect, fillrect, etc functions.


## Included program.h

The included program.h will update along with the repo. i am planning to make a demo operating system which wouldnt do much
