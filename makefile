# final executable file creation
output.exe: main.o addition.o subtraction.o multiplication.o division.o

	# linking all object files
	gcc -o output.exe main.o addition.o subtraction.o multiplication.o division.o


# compile main.c
main.o: main.c apc.h
	gcc -c main.c


# compile addition.c
addition.o: addition.c apc.h
	gcc -c addition.c


# compile subtraction.c
subtraction.o: subtraction.c apc.h
	gcc -c subtraction.c


# compile multiplication.c
multiplication.o: multiplication.c apc.h
	gcc -c multiplication.c


# compile division.c
division.o: division.c apc.h
	gcc -c division.c


# remove object and executable files
clean:
	rm *.o *.exe