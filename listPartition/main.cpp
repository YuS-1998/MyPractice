#include <iostream>
#include "list.h"

using namespace std;

//将链表按值划分成小于某个数区，等于区和大于区
void swap(PNODE *arr,int a,int b)
{
    PNODE t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
    return;
}

PNODE listPartition1(PNODE head, int pivot)
{//法一：准备一个数组，将链表的每个节点依次放进去，用partition的方法划分成三个区域，然后依次连接起来
    int num = 9;
    int i = 0;
    PNODE Arr[9];
    PNODE p = head;
    while(p != NULL)
    {//把链表中的节点都放到数组中，并断开它们之间的连接
        Arr[i] = p;
        p = p->next;
        Arr[i++]->next = NULL;
    }
    int less = -1;//小于区的右边界
    int more = num;//大于区的左边界
    i = 0;
    while(i != more)//partition
    {
        if(Arr[i]->value < pivot)
            swap(Arr,++less,i++);
        else
        {
            if(Arr[i]->value > pivot)
                swap(Arr,--more,i);
            else
                i++;
        }
    }
    for(i = 0; i < num-1; i++)//重新连接链表
        Arr[i]->next = Arr[i+1];
    return Arr[0];
}

PNODE listPartition2(PNODE head, int pivot)
{//法二：设六个变量：小于区的头尾节点，等于区的头尾节点，大于区的头尾节点，然后依次串联起来
    PNODE sH = NULL;//small head
    PNODE sT = NULL;//small tail
    PNODE eH = NULL;//equal head
    PNODE eT = NULL;//equal tail
    PNODE mH = NULL;//more head
    PNODE mT = NULL;//more tail
    PNODE next = NULL;//save next node
    while(head != NULL)
    {
        next = head->next;
        head->next = NULL;
        if(head->value < pivot)
        {
            if(sH == NULL){//如果小于区没有节点，就把小于区的头尾节点都设为当前节点
                sH = head;
                sT = head;
            }else{//否则将当前节点挂在小于区节点的后面
                sT->next = head;
                sT = head;
            }
        }
        else
        {
            if(head->value == pivot){
                if(eH == NULL){
                    eH = head;
                    eT = head;
                }else{
                    eT->next = head;
                    eT = head;
                }
            }else{
                if(mH == NULL){
                    mH = head;
                    mT = head;
                }else{
                    mT->next = head;
                    mT = head;
                }
            }
        }
        head = next;
    }
    //small and equal reconnect
    if(sT != NULL){//如果有小于区
        sT->next = eH;
        eT = eT == NULL ? sT : eT;//下一步，谁去连大于区的头，谁就变成eT
    }
    //all reconnect
    if(eT != NULL)
        eT->next = mH;
    return sH != NULL ? sH : (eH != NULL ? eH : mH);
}

int main()
{
    PNODE head = create_list();
    cout << "划分之前：";
    traverse_list(head->next);
    //PNODE newHead = listPartition1(head->next,5);
    PNODE newHead = listPartition2(head->next,5);
    cout << "划分之后：";
    traverse_list(newHead);
    return 0;
}
