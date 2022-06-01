# ya its a bad makefile

OUTPUT_FILE="game.exe"

run: *.c *.h
	gcc -o $(OUTPUT_FILE) *.c "C:\raylib\raylib\src\raylib.rc.data" -s -static -Os -std=c99 -Wall -IC:\raylib\raylib\src -Iexternal -DPLATFORM_DESKTOP -lraylib -lopengl32 -lgdi32 -lwinmm