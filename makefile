# ya its a bad makefile

OUTPUT_FILE="game.exe"

run: **/*.c **/*.h   **/**/*.c **/**/*.h   *.c *.h
	gcc -g -o $(OUTPUT_FILE) **/*.c **/**/*.c *.c -static -Os -std=c99 -Wall -Wextra -IC:\raylib\raylib\src -Iexternal -DPLATFORM_DESKTOP -lraylib -lopengl32 -lgdi32 -lwinmm
