default:
	gcc -Wall main.c ambassador.c visit.c util.c -o prog

debug:
	gcc -Wall -g main.c input.c -o prog

clean:
	del prog.exe