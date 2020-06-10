all: myk

myk:	gcc -o ls listdir.c
clean:
	rm *.o myk