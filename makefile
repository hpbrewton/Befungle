stack: stack.o
	gcc -o stack stack.o -Wall -Werror

topo.o: topo.h topo.c
	gcc topo.h -c topo.c

topo_test.o: topo.h topo.o topo_test.c
	gcc -o topo_test topo_test.c topo.h topo.o

test: topo_test.o
	topo_test

clean:
	rm *.o
	rm *.gch
	rm topo_test
	rm stack
