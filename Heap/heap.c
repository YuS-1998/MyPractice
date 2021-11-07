#include "heap.h"

void swap(int * Arr,int i,int j)
{
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
    return;
}

void traverse(int * Arr,int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%d ",Arr[i]);
    return;
}

void heapInsert(int * Arr, int index)
{
    while(Arr[index] > Arr[(index-1)/2])//跳出循环包含两种情况：1、当前节点不再比他的父节点的元素大了；2、当前节点已经到了整个堆的根了，没有父节点了（index=0时，(index-1)/2也=0，不满足循环条件）
    {
        swap(Arr,index,(index-1)/2);
        index = (index-1)/2;
    }
    return;
}

void heapify(int * Arr, int index, int heapSize)
{
    int left = index*2+1;//左孩子的下标
    while(left < heapSize)//heapSize用来判断是否越界的，当满足left < heapSize，说明有左孩子，即当前节点有孩子
    {
        int largest = left+1 < heapSize && Arr[left+1] > Arr[left] ? left+1 : left;//这里当有右孩子和右孩子比左孩子大同时成立时，largest=右孩子的下标，否则=左孩子的下标
        largest = Arr[largest] > Arr[index] ? largest : index;//比较两个孩子中较大那个和当前节点的大小
        if(largest == index)//如果当前节点元素大，说明该节点没法往下放了，跳出循环
            break;
        swap(Arr,index,largest);
        index = largest;
        left = index*2+1;
    }
    return;
}
