#include "Sort.h"

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

void selectSort(int * Arr, int len)//选择排序：从0到len-1遍历，找到i元素之后最小的值，并和i元素进行交换
{
    int i,j;
    if(Arr == NULL || len < 2)
        return;
    for(i = 0; i < len-1; i++)//i = 0 ~ N-1
    {
        int minIndex = i;
        for(j = i+1; j < len; j++)//在i+1~N上找最小值的下标
        {
            if(Arr[j] < Arr[minIndex])
                minIndex = j;
        }
        swap(Arr,i,minIndex);
    }
    return;
}

void bubbleSort(int * Arr, int len)//冒泡排序：从len到1遍历，依次将长度为i的数组中的最大值放在末尾（每次比较相邻两个元素，较大的那个放后面）
{
    int i,j;
    if(Arr == NULL || len < 2)
        return;
    for(i = len-1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(Arr[j] > Arr[j+1])
                swap(Arr,j,j+1);
        }
    }
    return;
}

void insertSort(int * Arr, int len)//从1到len遍历，依次排序好0-i的元素（当Arr[j]不再大于后面一个元素的时候就可以终止当前这个小循环，进行下一个排序了）
{
    int i,j;
    if(Arr == NULL || len < 2)
        return;
    for(i = 1; i < len; i++)//因为0~0一定是有序的
    {
        for(j = i-1; j >= 0 && Arr[j] > Arr[j+1]; j--)
            swap(Arr,j,j+1);
    }
    return;
}
