CC          =	gcc
# Flags that are sent to the compiler  change the std if you wish

CFLAGS      =	-Wall -std=c99 -pedantic -g -lm


# note that cpp check reports memory leaks on these files that wouldn't really be leaks when the program was run
# don't blindly believe everything it tells you- check to make sure it is correct.  Usually it is
# but not always.
#run cppcheck

prog: src/main2.c src/simulation.c src/HeapADT.c src/PQueueADT.c
	$(CC) $(CFLAGS) src/main2.c src/simulation.c src/HeapADT.c src/PQueueADT.c -Iinclude -o bin/runMe

noextra: src/main1.c src/simulation.c src/HeapADT.c src/PQueueADT.c
		$(CC) $(CFLAGS) src/main1.c src/simulation.c src/HeapADT.c src/PQueueADT.c -Iinclude -o bin/runYou

make runs:
		cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude src/*.c -i ./include

doxy: Doxyfile
	doxygen

clean:
	rm bin/*
