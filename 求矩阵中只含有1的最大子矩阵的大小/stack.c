#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

void initStack(pSTACK pS)//³õÊ¼»¯Õ»
{
    pS->pTop = (pNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("·ÖÅäÄÚ´æÊ§°Ü£¡");
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

void pushStack(pSTACK pS, int val)//Ñ¹Õ»
{
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("·ÖÅäÄÚ´æÊ§°Ü£¡");
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

bool popStack(pSTACK pS, int * pVal)//³öÕ»
{
    if(emptyStack(pS))
    {
        printf("³öÕ»Ê§°Ü£¡");
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
