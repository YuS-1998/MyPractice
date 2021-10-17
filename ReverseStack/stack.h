#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
    int data;
    struct  _node * pNext;
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
int getAndRemoveLast(pStack);//取出并删除栈底元素
void reverseStack(pStack);//仅利用递归和栈实现栈的逆序

#endif // STACK_H_INCLUDED
