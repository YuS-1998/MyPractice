#include "GetMin.h"

void initStack(pStack pS)
{
    pS->pTop = (pNode)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("分配空间失败！\n");
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
        printf("分配空间失败！\n");
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
        printf("栈为空，出栈失败！\n");
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

int getMin(pStack pS)
{
    int i,t;
    STACK Help;//生成一个辅助栈
    initStack(&Help);//初始化这个辅助栈

    //返回栈中最小值元素的方法：利用一个辅助栈
    //方法1：该辅助栈与原始栈同时压栈出栈，不同的是，当压入的数比辅助栈栈顶元素小时正常压入，但是大于等于栈顶元素时则压入的元素仍是此时的栈顶元素
//    for(i = 0; i < 7; i++)
//    {
//        printf("请输入你要压入栈的元素：\n");
//        scanf("%d",&t);
//        pushStack(pS,t);
//        if(t < Help.pTop->data)
//            pushStack(&Help,t);
//        else
//            pushStack(&Help,Help.pTop->data);
//    }
//    printf("原始栈为：\n");
//    traverseStack(pS);
//    printf("辅助栈为：\n");
//    traverseStack(&Help);
//    return Help.pTop->data;

    //方法2：与方法1类似，改成小于等于辅助栈栈顶元素时压入元素，大于时不压栈
    for(i = 0; i < 7; i++)
    {
        printf("请输入你要压入栈的元素：\n");
        scanf("%d",&t);
        pushStack(pS,t);
        if(t <= Help.pTop->data)
            pushStack(&Help,t);
    }
    printf("原始栈为：\n");
    traverseStack(pS);
    printf("辅助栈为：\n");
    traverseStack(&Help);
    return Help.pTop->data;
}
