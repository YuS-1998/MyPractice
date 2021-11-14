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

void selectSort(int * Arr, int len)//ѡ�����򣺴�0��len-1�������ҵ�iԪ��֮����С��ֵ������iԪ�ؽ��н���
{
    int i,j;
    if(Arr == NULL || len < 2)
        return;
    for(i = 0; i < len-1; i++)//i = 0 ~ N-1
    {
        int minIndex = i;
        for(j = i+1; j < len; j++)//��i+1~N������Сֵ���±�
        {
            if(Arr[j] < Arr[minIndex])
                minIndex = j;
        }
        swap(Arr,i,minIndex);
    }
    return;
}

void bubbleSort(int * Arr, int len)//ð�����򣺴�len��1���������ν�����Ϊi�������е����ֵ����ĩβ��ÿ�αȽ���������Ԫ�أ��ϴ���Ǹ��ź��棩
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

void insertSort(int * Arr, int len)//��1��len���������������0-i��Ԫ�أ���Arr[j]���ٴ��ں���һ��Ԫ�ص�ʱ��Ϳ�����ֹ��ǰ���Сѭ����������һ�������ˣ�
{
    int i,j;
    if(Arr == NULL || len < 2)
        return;
    for(i = 1; i < len; i++)//��Ϊ0~0һ���������
    {
        for(j = i-1; j >= 0 && Arr[j] > Arr[j+1]; j--)
            swap(Arr,j,j+1);
    }
    return;
}
