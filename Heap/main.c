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
        printf("������һ����������");
        scanf("%d",&val);
        Arr[i] = val;
        heapInsert(Arr,i);
    }
    traverse(Arr,heapSize);
    printf("\n");
    //ȡ���������ֵ������ʱ�ѵĸ��ڵ��Ԫ�أ�������ɾ����
    //Ȼ��ʣ�µĶ����ųɴ����
    val = Arr[0];
    printf("����������ֵΪ%d\n",val);
    Arr[0] = Arr[heapSize-1];
    heapSize--;//�����������һ����ɾ������ʱΪ�����е����ֵ��
    traverse(Arr,heapSize);
    printf("\n");
    heapify(Arr,0,heapSize);
    traverse(Arr,heapSize);
    return 0;
}
