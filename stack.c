#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

bstack *
init () {
    bstack *stack = malloc(sizeof(bstack));
    stack->used   = 0;
    stack->size   = 64;
    stack->stack  = malloc((stack->size)*sizeof(char));
    return stack;
}

void
freeStack (bstack *stack) {
    free(stack->stack);
    free(stack);
}

void
push (bstack *stack, int val) {
    if (stack->used == stack->size) {
        stack->stack = realloc(stack->stack, 2*(stack->size));
        if (!(stack->stack))
            exit(0);
    }
    stack->stack[(stack->used)++] = val; 
}

int
pop (bstack *stack) {
    assert (stack->used > 0); 
    return stack->stack[--(stack->used)];
}

void
fungePush (bstack *stack, int val) {
    if (val < 10) {
        push(stack, val);
    } else if (val == '+') {
        push(stack, pop(stack) + pop(stack));
    } else if (val == '-') {
        push(stack, -pop(stack) + pop(stack));
    } else if (val == '*') {
        push(stack, pop(stack) * pop(stack));
    } else if (val == '/') {
        int a = pop(stack);
        int b = pop(stack);
        push(stack, b/a);
    } else if (val == '%') {
        int a = pop(stack);
        int b = pop(stack);
        push(stack, b%a);
    } else if (val == '!') {
        push(stack, !pop(stack));
    } else if (val == '`') {
        int a = pop(stack);
        int b = pop(stack);
        push(stack, (b>a) ? 1 : 0);
    } else if (val == ':') {
        int a = pop(stack);
        push(stack, a); 
        push(stack, a);
    } else if (val == '\\') {
        int a = pop(stack);
        int b = pop(stack);
        push(stack, a); push(stack, b);
    } else if (val == '$') {
        pop(stack);
    } else if (val == '&') {
        int num;
        scanf("%d", &num);
        push(stack, num);
    } else if (val == '~') {
        char num;
        scanf("%c", &num);
        push(stack, num);
    }
}

int
main (int argc, char *argv[]) {
    bstack *stack = init();
    for (int i = 0; i < 10; ++i)
        push(stack, i);
    for (int i = 0; i < 10; ++i)
        printf("%d\n", pop(stack));
    freeStack(stack);
}
