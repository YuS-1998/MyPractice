#include "list.h"
using namespace std;

PNODE create_list()
{
    int len;//用来存放有效节点的个数
    int i;
    int val;//用来临时存放用户输入的节点的值

    //分配了一个不存放有效数据的头节点
    PNODE pHead = new NODE;
    if(NULL == pHead)
    {
        cout << "分配失败，程序终止！\n";
        exit(-1);
    }

    PNODE pTail = pHead;//创造一个指针，始终指向尾节点；
    pTail->next = NULL;

    cout << "请输入您需要生成的链表节点的个数：len = ";
    cin >> len;

    for(i = 0; i < len; i++)
    {
        cout << "请输入第" << i+1 << "个节点的值：";
        cin >> val;

        PNODE pNew = new NODE;
        if(NULL == pNew)
        {
            cout << "分配失败，程序终止！\n";
            exit(-1);
        }

        pNew->value = val;
        pTail->next = pNew;//将这个新节点挂到前面的尾节点的后面

        pNew->next = NULL;//将这个新节点的指针域清空，好让它作为新的尾节点
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

    for(i = 0, p = pHead->next; i < len-1; i++, p = p->next)//p最开始指向第一个有效节点，即头结点后的一个节点，然后i++的同时，p向后一个节点移动
    {
        for(j = i+1, q = p->next; j < len; j++,q = q->next)//q最开始指向p的下一个节点，然后j++的同时， q向后一个节点移动
        {
            if(p->value > q->value)//类似于数组中的：a[i] > a[j]
            {
                t = p->value;//t = a[i];
                p->value = q->value;//a[i] = a[j];
                q->value = t;//a[j] = t;
            }
        }
    }
    return;
}

bool insert_list(PNODE pHead, int pos, int val)//在pHead所指向的链表的第pos个节点的前面插入一个新的节点，该节点的值时val，并且pos的值是从1开始的
{
    int i = 0;
    PNODE p = pHead->next;//p最开始指向第一个有效节点

    while(NULL != p && i < pos-1)
    {
        p = p->next;
        i++;
    }//这一步是将指针p移到pos这个节点的前面

    if(i > pos-1 || NULL == p)
        return false;

    PNODE pNew = new NODE;
    if(NULL == pNew)
    {
        cout << "动态分配内存失败！\n";
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
    PNODE p = pHead->next;//p最开始指向第一个有效节点

    while(NULL != p->next && i < pos-1)
    {
        p = p->next;
        i++;
    }//这一步是将指针p移到pos这个节点的前面

    if(i > pos-1 || NULL == p->next)
        return false;

    PNODE q = p->next;
    *pVal = q->value;

    //删除p节点后面的节点
    p->next = p->next->next;
    free(q);
    q = NULL;

    return true;
}
