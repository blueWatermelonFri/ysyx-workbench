all: main

main: main.o test1.o test2.o
	gcc -O1 -o main main.o test1.o test2.o
	./main

main.o: main.c
	gcc -O1 -c main.c

test1.o: test1.c
	gcc -O1 -c test1.c

test2.o: test2.c
	gcc -O1 -c test2.c

clean:
	rm -f *.o