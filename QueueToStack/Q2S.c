#include "Q2S.h"

void initQueue(pQueue pQ)
{
    pQ->pFront = (pNode)malloc(sizeof(NODE));
    if(NULL == pQ->pFront)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�\n");
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
        printf("����Ϊ�գ�����ʧ�ܣ�\n");
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
    QUEUE Help;//��������
    initQueue(&Help);

    for(i = 0; i < 7; i++)//�������
    {
        printf("��������Ҫѹ��ջ��Ԫ�أ�");
        scanf("%d",&t);
        addQueue(pQ,t);
    }
    printf("ԭʼ����Ϊ��\n");
    traverseQueue(pQ);
    printf("\n");
    printf("���������У��Ƚ��ȳ���ʵ��ջ���Ƚ��������");
    while(!isEmpty(pQ))
    {
        while(pQ->pFront->pNext != pQ->pRear)//��ԭ������ʣ��һ��Ԫ�أ������ѹ����е�Ԫ�أ���Ȼ�����Ԫ�س��ӣ��Ӷ�ʵ�ֺ���ȳ�
        {
            pollQueue(pQ,&val);
            addQueue(&Help,val);
        }
        pollQueue(pQ,&val);
        printf("%d ",val);
        while(!isEmpty(&Help))//�ٶ�װ��ȥ
        {
            pollQueue(&Help,&val);
            addQueue(pQ,val);
        }
    }
    return;
}
