#include "Q2S.h"

void initQueue(pQueue pQ)
{
    pQ->pFront = (pNode)malloc(sizeof(NODE));
    if(NULL == pQ->pFront)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    else
    {
        pQ->pRear = pQ->pFront;
        pQ->pRear->pNext = NULL;
    }
    return;
}

void addQueue(pQueue pQ, int val)
{
    pNode pNew = (pNode)malloc(sizeof(NODE));
    pNew->pNext = NULL;
    if(NULL == pNew)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    else
    {
        pQ->pRear->data = val;
        pQ->pRear->pNext = pNew;
        pQ->pRear = pNew;
    }
    return;
}

bool isEmpty(pQueue pQ)
{
    if(pQ->pRear == pQ->pFront)
        return true;
    else
        return false;
}

bool pollQueue(pQueue pQ, int * pVal)
{
    if(isEmpty(pQ))
    {
        printf("队列为空！出队失败！\n");
        return false;
    }
    else
    {
        pNode r = pQ->pFront;
        *pVal = r->data;
        pQ->pFront = pQ->pFront->pNext;
        free(r);
        r = NULL;
        return true;
    }
}

void traverseQueue(pQueue pQ)
{
    pNode p = pQ->pFront;
    while(p != pQ->pRear)
    {
        printf("%d ",p->data);
        p = p->pNext;
    }
    return;
}

void Q2S(pQueue pQ)
{
    int i,t;
    int val;
    QUEUE Help;//辅助队列
    initQueue(&Help);

    for(i = 0; i < 7; i++)//输入操作
    {
        printf("请输入你要压入栈的元素：");
        scanf("%d",&t);
        addQueue(pQ,t);
    }
    printf("原始队列为：\n");
    traverseQueue(pQ);
    printf("\n");
    printf("用两个队列（先进先出）实现栈（先进后出）：");
    while(!isEmpty(pQ))
    {
        while(pQ->pFront->pNext != pQ->pRear)//在原队列中剩下一个元素（即最后压入队列的元素），然后将这个元素出队，从而实现后进先出
        {
            pollQueue(pQ,&val);
            addQueue(&Help,val);
        }
        pollQueue(pQ,&val);
        printf("%d ",val);
        while(!isEmpty(&Help))//再都装回去
        {
            pollQueue(&Help,&val);
            addQueue(pQ,val);
        }
    }
    return;
}
