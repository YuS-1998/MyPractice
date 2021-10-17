#ifndef GETMIN_H_INCLUDED
#define GETMIN_H_INCLUDED
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
int getMin(pStack);

#endif // GETMIN_H_INCLUDED
