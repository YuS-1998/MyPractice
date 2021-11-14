#include "Sort.h"

int GetSrand(int * arr,int len)
{
     srand(time(0));
     return arr[rand()%len];
}

void quickSort1(int * Arr, int L, int R)//����1.0�汾��ֻ��С�ڵ������ʹ�������ÿ�εݹ�ֻ���ź���Ϊ���ֱ�׼���Ǹ�����Arr[R]��
{
    if(L < R)
    {
        int less;
        partition1(Arr,L,R,&less);
        quickSort1(Arr,L,less-1);//С�ڵ���������
        quickSort1(Arr,less+1,R);//����������
    }
}

void quickSort2(int * Arr, int L, int R)//����2.0�汾������С��������������������������ÿ�εݹ������������λ�þ͹̶��ˣ����1.0�汾ÿ�ζ��ź�һЩ��������һЩ
{
    if(L < R)
    {
        int b1,b2;
        partition2(Arr,L,R,&b1,&b2);
        quickSort2(Arr,L,b1-1);//С��������
        quickSort2(Arr,b2+1,R);//����������
    }
}
//ǰ�����汾�ĸ��Ӷȶ���O(N^2)

void quickSort3(int * Arr, int L, int R)//����3.0�汾����2.0�汾�Ļ����ϣ�ÿ����Ϊ���ֱ�׼���������ǹ̶���Arr[R]�ˣ����������һ�������������ӶȾͱ����O(NlogN)
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int r = GetSrand(a,R-L+1);
    if(L < R)
    {
        int b1,b2;
        swap(Arr,L+r,R);//�����ѡ��������������ֵ��������������������
        partition2(Arr,L,R,&b1,&b2);
        quickSort3(Arr,L,b1-1);//С��������
        quickSort3(Arr,b2+1,R);//����������
    }
}

void partition1(int * Arr, int L, int R, int * pLess)
{
    int less = L-1;//С�ڵ��������ұ߽�
    while(L <= R)//L��ʾ��ǰԪ��λ��
    {//����ͬ���������������
        if(Arr[L] <= Arr[R])
        {
            swap(Arr,L,less+1);
            less++;
            L++;
        }
        else
            L++;
    }
    *pLess = less;
    return;
}

void partition2(int * Arr, int L, int R, int * pb1, int * pb2)
{
    int less = L-1;//С�������ұ߽�
    int more = R;//����������߽磬Arr[R]Ϊ����ֵ
    while(L < more)//L��ʾ��ǰԪ��λ��
    {//����ͬ������������
        if(Arr[L] < Arr[R])
            swap(Arr,++less,L++);
        else
        {
            if(Arr[L] > Arr[R])
                swap(Arr,--more,L);
            else
                L++;
        }
    }
    swap(Arr,R,more);//����Arr[R]��Arr[more]��ʹ����ֵҲ����������
    *pb1 = less+1;//����������߽�
    *pb2 = more;//�������ұ߽�
    return;
}
