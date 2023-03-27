clox: main.c memory.c chunk.c value.c vm.c debug.c
	gcc -std=c99 -Wall main.c memory.c chunk.c value.c vm.c debug.c -o clox

run: clox
	./clox
