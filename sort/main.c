#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

int main()
{
    int arrSize = 10;
    int Arr[10] = {
        1, 5, 6, 3, 8, 2, 4, 0, 9, 7
    };
    int Arr2[10] = {
        128, 99, 56, 1024, 65, 999, 47, 666, 425, 3
    };
    printf("排序前：");
    //traverse(Arr,arrSize);
    //printf("\n");
    traverse(Arr2,arrSize);
    printf("\n");
    //selectSort(Arr,arrSize);//选择排序
    //bubbleSort(Arr,arrSize);//冒泡排序
    //insertSort(Arr,arrSize);//插入排序
    //mergeSort(Arr,0,arrSize-1);//归并排序
    //quickSort1(Arr,0,arrSize-1);//快排
    //quickSort2(Arr,0,arrSize-1);
    //quickSort3(Arr,0,arrSize-1);
    //heapSort(Arr,arrSize);//堆排序
    radixSort(Arr2,0,9);//基数排序
    printf("排序后：");
    //traverse(Arr,arrSize);
    traverse(Arr2,arrSize);
    return 0;
}
