stack: stack.o
	gcc -o stack stack.o -Wall -Werror

topo.o: topo.h
	gcc topo.h -c topo.c

clean:
	rm *.o
	rm *.gch
	rm stack
