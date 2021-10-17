#include "GetMin.h"

void initStack(pStack pS)
{
    pS->pTop = (pNode)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("����ռ�ʧ�ܣ�\n");
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
        printf("����ռ�ʧ�ܣ�\n");
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
        printf("ջΪ�գ���ջʧ�ܣ�\n");
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
    STACK Help;//����һ������ջ
    initStack(&Help);//��ʼ���������ջ

    //����ջ����СֵԪ�صķ���������һ������ջ
    //����1���ø���ջ��ԭʼջͬʱѹջ��ջ����ͬ���ǣ���ѹ������ȸ���ջջ��Ԫ��Сʱ����ѹ�룬���Ǵ��ڵ���ջ��Ԫ��ʱ��ѹ���Ԫ�����Ǵ�ʱ��ջ��Ԫ��
//    for(i = 0; i < 7; i++)
//    {
//        printf("��������Ҫѹ��ջ��Ԫ�أ�\n");
//        scanf("%d",&t);
//        pushStack(pS,t);
//        if(t < Help.pTop->data)
//            pushStack(&Help,t);
//        else
//            pushStack(&Help,Help.pTop->data);
//    }
//    printf("ԭʼջΪ��\n");
//    traverseStack(pS);
//    printf("����ջΪ��\n");
//    traverseStack(&Help);
//    return Help.pTop->data;

    //����2���뷽��1���ƣ��ĳ�С�ڵ��ڸ���ջջ��Ԫ��ʱѹ��Ԫ�أ�����ʱ��ѹջ
    for(i = 0; i < 7; i++)
    {
        printf("��������Ҫѹ��ջ��Ԫ�أ�\n");
        scanf("%d",&t);
        pushStack(pS,t);
        if(t <= Help.pTop->data)
            pushStack(&Help,t);
    }
    printf("ԭʼջΪ��\n");
    traverseStack(pS);
    printf("����ջΪ��\n");
    traverseStack(&Help);
    return Help.pTop->data;
}
