all:
	gcc -framework OpenGL -framework GLUT crosseye.c -o crosseye -Wno-deprecated-declarations

clean:
	rm -f crosseye
	