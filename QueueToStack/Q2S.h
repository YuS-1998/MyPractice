#ifndef Q2S_H_INCLUDED
#define Q2S_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct _node{
    int data;//Êý¾ÝÓò
    struct  _node * pNext;//Ö¸ÕëÓò
}NODE, * pNode;

typedef struct _queue{
    pNode pFront;
    pNode pRear;
}QUEUE, * pQueue;

void initQueue(pQueue);
void addQueue(pQueue, int );
bool isEmpty(pQueue);
bool pollQueue(pQueue, int * );
void traverseQueue(pQueue);
void Q2S(pQueue);

#endif // Q2S_H_INCLUDED
