stack: stack.o
	gcc -o stack stack.o -Wall -Werror

clean:
	rm stack
	rm *.o
