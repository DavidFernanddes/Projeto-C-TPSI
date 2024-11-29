default:
	gcc -Wall main.c date.c zodiac.c -o prog

debug:
	gcc -Wall -g main.c input.c -o prog

clean:
	del prog.exe