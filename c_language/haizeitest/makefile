.PHONY: clean

all: main.o test.o
	gcc main.o test.o -lm -o haizeix
main.o: main.c test.h
	gcc -I./ -c main.c
test.o: test.c test.h linklist.h
	gcc -I./ -c test.c
clean:
	rm -rf main.o test.o haizeix
