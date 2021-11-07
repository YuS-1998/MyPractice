#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    int i;
    int val;
    int heapSize = 7;
    int Arr[heapSize];
    for(i = 0; i < heapSize; i++)
    {
        printf("请输入一个正整数：");
        scanf("%d",&val);
        Arr[i] = val;
        heapInsert(Arr,i);
    }
    traverse(Arr,heapSize);
    printf("\n");
    //取出数组最大值，即此时堆的根节点的元素，并将它删除。
    //然后将剩下的堆仍排成大根堆
    val = Arr[0];
    printf("该数组的最大值为%d\n",val);
    Arr[0] = Arr[heapSize-1];
    heapSize--;//即将数组最后一个数删除（此时为数组中的最大值）
    traverse(Arr,heapSize);
    printf("\n");
    heapify(Arr,0,heapSize);
    traverse(Arr,heapSize);
    return 0;
}
