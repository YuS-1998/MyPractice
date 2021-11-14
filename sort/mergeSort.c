#include "Sort.h"

//递归的复杂度要用master公式，这里a=2,b=2,d=1，所以归并排序的时间复杂度为O(NlogN)
void mergeSort(int * Arr, int L,int R)//使用递归，每次取一半，用merge函数排序好左边一半，再排序好右边一半，再合起来一起排序
{
    if(L == R)
        return;
    int mid = L+(R-L)/2;//，这样可以避免溢栈，也可写作L+(R-L)>>1，即向右移一位，也就是除以2
    mergeSort(Arr,L,mid);
    mergeSort(Arr,mid+1,R);
    merge(Arr,L,mid,R);
}

void merge(int * Arr, int L, int M, int R)//设此时数组的左半边和右半边都排好序了，这个函数用两个指针和一个辅助数组，将左右两个数组按从小到大的顺序再合并起来
{
    int Help[R-L+1];
    int i = 0;
    int j;
    int p1 = L;
    int p2 = M+1;
    while(p1 <= M && p2 <= R)//p1和p2均没有超出范围则谁小就排谁
    {
        if(Arr[p1] <= Arr[p2])
        {
            Help[i] = Arr[p1];
            p1++;
            i++;
        }
        else
        {
            Help[i] = Arr[p2];
            p2++;
            i++;
        }
    }
    while(p1 <= M)//其中一个超出了范围，就把另一个排完
    {
        Help[i] = Arr[p1];
        p1++;
        i++;
    }
    while(p2 <= R)
    {
        Help[i] = Arr[p2];
        p2++;
        i++;
    }
//    traverse(Help,i);
//    printf("\n");
    for(j = 0; j < i; j++)
        Arr[L+j] = Help[j];
    return;
}
