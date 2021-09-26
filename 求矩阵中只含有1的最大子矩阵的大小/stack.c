#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

void initStack(pSTACK pS)//��ʼ��ջ
{
    pS->pTop = (pNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("�����ڴ�ʧ�ܣ�");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
    return;
}

bool emptyStack(pSTACK pS)
{
    if(pS->pBottom == pS->pTop)
        return true;
    else
        return false;
}

void pushStack(pSTACK pS, int val)//ѹջ
{
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("�����ڴ�ʧ�ܣ�");
        exit(-1);
    }
    else
    {
        pNew->data = val;
        pNew->pNext = pS->pTop;
        pS->pTop = pNew;
    }
    return;
}

bool popStack(pSTACK pS, int * pVal)//��ջ
{
    if(emptyStack(pS))
    {
        printf("��ջʧ�ܣ�");
        return false;
    }
    else
    {
        pNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }
}
