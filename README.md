# READ ME!

BSCR stands for Basic Sandboxed C Runtime, and its basically like the average C emulator, exept replace the input .bin file with an included C source.


## HOW TO COMPILE!

Make sure you are in repo-root/ (not actual folder name, example) and run this command

```bash
gcc src/main.c -o bin/out
```

Dont worry, you dont have to compile program.h.

## HOW TO WRITE CODE FOR THIS!

You can write code by editing the program.h file.
If you dont want to write inline everywhere, you can also write a program.c file.
Your program needs an init(uint8_t* mem) function and an update(uint8_t* mem) function.
