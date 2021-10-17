#include "S2Q.h"

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
    STACK Help;//����һ������ջ
    initStack(&Help);//��ʼ���������ջ

    //һ��������ջһ�������ջ
    //ԭ����1������ջ�����ջ�Ĺ���ÿ�ζ�Ҫ�ſ�����ջ��2������ջ��ʼ�����ջ��ʱ�����ջ�в�����Ԫ��
    for(i = 0; i < 7; i++)//�������
    {
        printf("��������Ҫѹ����е�Ԫ�أ�");
        scanf("%d",&t);
        pushStack(pS,t);
    }
    printf("ԭʼջΪ��\n");
    traverseStack(pS);
    if(isEmpty(&Help))//ԭ��2
    {
        while(!isEmpty(pS))//ԭ��1
        {
            //��ջS�е���Ԫ��ѹ�븨��ջ�У���ɵ�������
            popStack(pS,&val);
            pushStack(&Help,val);
        }
    }
    else
        return;
    printf("����ջΪ��\n");
    traverseStack(&Help);
    printf("������ջ���Ƚ������ʵ�ֶ��У��Ƚ��ȳ�����");
    emptyStack(&Help);//�������
    return;
}
