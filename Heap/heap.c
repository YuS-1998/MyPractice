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
    while(Arr[index] > Arr[(index-1)/2])//����ѭ���������������1����ǰ�ڵ㲻�ٱ����ĸ��ڵ��Ԫ�ش��ˣ�2����ǰ�ڵ��Ѿ����������ѵĸ��ˣ�û�и��ڵ��ˣ�index=0ʱ��(index-1)/2Ҳ=0��������ѭ��������
    {
        swap(Arr,index,(index-1)/2);
        index = (index-1)/2;
    }
    return;
}

void heapify(int * Arr, int index, int heapSize)
{
    int left = index*2+1;//���ӵ��±�
    while(left < heapSize)//heapSize�����ж��Ƿ�Խ��ģ�������left < heapSize��˵�������ӣ�����ǰ�ڵ��к���
    {
        int largest = left+1 < heapSize && Arr[left+1] > Arr[left] ? left+1 : left;//���ﵱ���Һ��Ӻ��Һ��ӱ����Ӵ�ͬʱ����ʱ��largest=�Һ��ӵ��±꣬����=���ӵ��±�
        largest = Arr[largest] > Arr[index] ? largest : index;//�Ƚ����������нϴ��Ǹ��͵�ǰ�ڵ�Ĵ�С
        if(largest == index)//�����ǰ�ڵ�Ԫ�ش�˵���ýڵ�û�����·��ˣ�����ѭ��
            break;
        swap(Arr,index,largest);
        index = largest;
        left = index*2+1;
    }
    return;
}
