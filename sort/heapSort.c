#include "Sort.h"

void heapSort(int * Arr, int len)//先用heapInsert让数组成为一个大根堆，然后交换第一个数和最后一个数，使最大值放到数组的最后
//然后将最后一个数之前的数组再排成大根堆，再将最大的数放到最后，依次类推，完成排序
{
    int i;
    if(Arr == NULL || len < 2)
        return;
    for(i = 0; i < len; i++)//O(N)
        heapInsert(Arr,i);//O(logN)
    //将一个给定的数组排成大根堆，有更快的方法：从最后一个节点从右向左，从下到上进行heapify，这样这一步的复杂度为O(N)，但是对整个堆排序的复杂度没有影响
    //for(i = len-1; i >= 0; i--)
    //  heapify(Arr,i,len);
    int heapSize = len;
    swap(Arr,0,--heapSize);
    while(heapSize > 0)//O(N)
    {
        heapify(Arr,0,heapSize);//O(logN)
        swap(Arr,0,--heapSize);//O(1)
    }
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
