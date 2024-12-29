all: main

main: main.o test1.o
	gcc  -o main main.o test1.o 
	./main

main.o: main.c
	gcc  -c main.c

test1.o: test1.c
	gcc  -c test1.c


clean:
	rm -f *.o