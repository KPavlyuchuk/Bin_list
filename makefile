FLAGS=-fprofile-arcs -ftest-coverage
all: tests
tests: tests.o list.o
	gcc list.o tests.o -o tests ${FLAGS}
tests.o: tests.c
	gcc -c tests.c -o tests.o ${FLAGS}
list.o: list.c
	gcc -c list.c -o list.o ${FLAGS}
clean:
	rm -rf tests *.o *.gcno *.gcda
