#include "S2Q.h"

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

void S2Q(pStack pS)
{
    int i,t;
    int val;
    STACK Help;//生成一个辅助栈
    initStack(&Help);//初始化这个辅助栈

    //一个做输入栈一个做输出栈
    //原则是1、输入栈到输出栈的过程每次都要排空输入栈；2、输入栈开始到输出栈的时候输出栈中不能有元素
    for(i = 0; i < 7; i++)//输入操作
    {
        printf("请输入你要压入队列的元素：");
        scanf("%d",&t);
        pushStack(pS,t);
    }
    printf("原始栈为：\n");
    traverseStack(pS);
    if(isEmpty(&Help))//原则2
    {
        while(!isEmpty(pS))//原则1
        {
            //从栈S中弹出元素压入辅助栈中，完成倒序排列
            popStack(pS,&val);
            pushStack(&Help,val);
        }
    }
    else
        return;
    printf("辅助栈为：\n");
    traverseStack(&Help);
    printf("用两个栈（先进后出）实现队列（先进先出）：");
    emptyStack(&Help);//输出操作
    return;
}
