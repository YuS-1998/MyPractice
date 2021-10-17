#ifndef S2Q_H_INCLUDED
#define S2Q_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
    int data;// ˝æ›”Ú
    struct  _node * pNext;//÷∏’Î”Ú
}NODE, * pNode;

typedef struct _stack{
    pNode pTop;
    pNode pBottom;
}STACK, * pStack;

void initStack(pStack);
void pushStack(pStack, int);
bool isEmpty(pStack);
bool popStack(pStack, int *);
void traverseStack(pStack);
void emptyStack(pStack);
void S2Q(pStack);


#endif // S2Q_H_INCLUDED
