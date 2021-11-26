#include "list.h"
using namespace std;

PNODE create_list()
{
    int len;//���������Ч�ڵ�ĸ���
    int i;
    int val;//������ʱ����û�����Ľڵ��ֵ

    //������һ���������Ч���ݵ�ͷ�ڵ�
    PNODE pHead = new NODE;
    if(NULL == pHead)
    {
        cout << "����ʧ�ܣ�������ֹ��\n";
        exit(-1);
    }

    PNODE pTail = pHead;//����һ��ָ�룬ʼ��ָ��β�ڵ㣻
    pTail->next = NULL;

    cout << "����������Ҫ���ɵ�����ڵ�ĸ�����len = ";
    cin >> len;

    for(i = 0; i < len; i++)
    {
        cout << "�������" << i+1 << "���ڵ��ֵ��";
        cin >> val;

        PNODE pNew = new NODE;
        if(NULL == pNew)
        {
            cout << "����ʧ�ܣ�������ֹ��\n";
            exit(-1);
        }

        pNew->value = val;
        pTail->next = pNew;//������½ڵ�ҵ�ǰ���β�ڵ�ĺ���

        pNew->next = NULL;//������½ڵ��ָ������գ���������Ϊ�µ�β�ڵ�
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead;

    while(NULL != p)
    {
        cout << p->value;
        p = p->next;
    }
    cout << "\n";
    return;
}

bool is_empty(PNODE pHead)
{
    if(NULL == pHead->next)
        return true;
    else
        return false;
}

int length_list(PNODE pHead)
{
    PNODE p = pHead->next;
    int len = 0;

    while(NULL != p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void sort_list(PNODE pHead)
{
    int i, j, t;
    int len = length_list(pHead);
    PNODE p,q;

    for(i = 0, p = pHead->next; i < len-1; i++, p = p->next)//p�ʼָ���һ����Ч�ڵ㣬��ͷ�����һ���ڵ㣬Ȼ��i++��ͬʱ��p���һ���ڵ��ƶ�
    {
        for(j = i+1, q = p->next; j < len; j++,q = q->next)//q�ʼָ��p����һ���ڵ㣬Ȼ��j++��ͬʱ�� q���һ���ڵ��ƶ�
        {
            if(p->value > q->value)//�����������еģ�a[i] > a[j]
            {
                t = p->value;//t = a[i];
                p->value = q->value;//a[i] = a[j];
                q->value = t;//a[j] = t;
            }
        }
    }
    return;
}

bool insert_list(PNODE pHead, int pos, int val)//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵʱval������pos��ֵ�Ǵ�1��ʼ��
{
    int i = 0;
    PNODE p = pHead->next;//p�ʼָ���һ����Ч�ڵ�

    while(NULL != p && i < pos-1)
    {
        p = p->next;
        i++;
    }//��һ���ǽ�ָ��p�Ƶ�pos����ڵ��ǰ��

    if(i > pos-1 || NULL == p)
        return false;

    PNODE pNew = new NODE;
    if(NULL == pNew)
    {
        cout << "��̬�����ڴ�ʧ�ܣ�\n";
        exit(-1);
    }
    pNew->value = val;
    PNODE q = p->next;
    p->next = pNew;
    pNew->next = q;

    return true;
}

bool delete_list(PNODE pHead, int pos, int *pVal)
{
    int i = 0;
    PNODE p = pHead->next;//p�ʼָ���һ����Ч�ڵ�

    while(NULL != p->next && i < pos-1)
    {
        p = p->next;
        i++;
    }//��һ���ǽ�ָ��p�Ƶ�pos����ڵ��ǰ��

    if(i > pos-1 || NULL == p->next)
        return false;

    PNODE q = p->next;
    *pVal = q->value;

    //ɾ��p�ڵ����Ľڵ�
    p->next = p->next->next;
    free(q);
    q = NULL;

    return true;
}
