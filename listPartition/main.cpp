#include <iostream>
#include "list.h"

using namespace std;

//������ֵ���ֳ�С��ĳ���������������ʹ�����
void swap(PNODE *arr,int a,int b)
{
    PNODE t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
    return;
}

PNODE listPartition1(PNODE head, int pivot)
{//��һ��׼��һ�����飬�������ÿ���ڵ����ηŽ�ȥ����partition�ķ������ֳ���������Ȼ��������������
    int num = 9;
    int i = 0;
    PNODE Arr[9];
    PNODE p = head;
    while(p != NULL)
    {//�������еĽڵ㶼�ŵ������У����Ͽ�����֮�������
        Arr[i] = p;
        p = p->next;
        Arr[i++]->next = NULL;
    }
    int less = -1;//С�������ұ߽�
    int more = num;//����������߽�
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
    for(i = 0; i < num-1; i++)//������������
        Arr[i]->next = Arr[i+1];
    return Arr[0];
}

PNODE listPartition2(PNODE head, int pivot)
{//������������������С������ͷβ�ڵ㣬��������ͷβ�ڵ㣬��������ͷβ�ڵ㣬Ȼ�����δ�������
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
            if(sH == NULL){//���С����û�нڵ㣬�Ͱ�С������ͷβ�ڵ㶼��Ϊ��ǰ�ڵ�
                sH = head;
                sT = head;
            }else{//���򽫵�ǰ�ڵ����С�����ڵ�ĺ���
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
    if(sT != NULL){//�����С����
        sT->next = eH;
        eT = eT == NULL ? sT : eT;//��һ����˭ȥ����������ͷ��˭�ͱ��eT
    }
    //all reconnect
    if(eT != NULL)
        eT->next = mH;
    return sH != NULL ? sH : (eH != NULL ? eH : mH);
}

int main()
{
    PNODE head = create_list();
    cout << "����֮ǰ��";
    traverse_list(head->next);
    //PNODE newHead = listPartition1(head->next,5);
    PNODE newHead = listPartition2(head->next,5);
    cout << "����֮��";
    traverse_list(newHead);
    return 0;
}
