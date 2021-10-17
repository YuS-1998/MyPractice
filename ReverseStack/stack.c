#include "stack.h"

void initStack(pStack pS)
{
    pS->pTop = (pNode)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("·ÖÅä¿Õ¼äÊ§°Ü£¡\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
    return;
}

void pushStack(pStack pS, int val)
{
    pNode pNew = (pNode)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("·ÖÅä¿Õ¼äÊ§°Ü£¡\n");
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

bool isEmpty(pStack pS)
{
    if(pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

bool popStack(pStack pS, int * pVal)
{
    if(isEmpty(pS))
    {
        printf("Õ»Îª¿Õ£¬³öÕ»Ê§°Ü£¡\n");
        return false;
    }
    else
    {
        pNode r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
}

void traverseStack(pStack pS)
{
    pNode p = pS->pTop;
    while(p != pS->pBottom)
    {
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

void emptyStack(pStack pS)
{
    int val;
    while(pS->pTop != pS->pBottom)
    {
        popStack(pS,&val);
        printf("%d ",val);
    }
    return;
}
