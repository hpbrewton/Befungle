#ifndef _STACK_H_
#define  _STACK_H_

typedef struct bstack {
    int *stack;
    int used;
    int size;
} bstack;

bstack *init (); 
void freeStack (bstack *stack);
void fungePush (bstack *stack, int val);

#endif //_STACK_H_
