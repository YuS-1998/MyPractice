#include "Sort.h"

int getDigit(int num, int d)//Ҫȡ��num�ĵ�dλ�����������㣩
{
    int b = num / pow(10,d-1);
    int a = b % 10;
    return a;
}

void radixSort(int * Arr, int L, int R)
{
    int i,j,d;
    int max = Arr[L];
    int digit = 0;//�����е�Ԫ�������digitλ
    int radix = 10;//��ʾÿһλ�ϵ����ֶ�ֻ��10�ֿ��ܣ�0~9��
    int bucket[R-L+1];//�м�������Ҫ׼�����������ռ�
    //�ȵõ����������������м�λ���������е�Ԫ������м�λ
    for(i = L+1; i <= R; i++)
        max = Arr[i] > max ? Arr[i] : max;
    while(max != 0)
    {
        digit++;
        max /= 10;
    }

    for(d = 1; d <= digit; d++)//�м�λ��Ҫ����Ͱ����
    {
        int count[radix];
        for(i = 0; i < radix; i++)
            count[i] = 0;
        for(i = L; i <= R; i++)
        {
            j = getDigit(Arr[i],d);
            count[j]++;//����count[j]��ʾ��dλ��j�������м���
        }
        for(i = 1; i < radix; i++)
            count[i] += count[i-1];//����count[i]��ʾ��dλС�ڵ���i�������м���
        for(i = R; i >= L; i--)
        {
            j = getDigit(Arr[i],d);
            bucket[count[j]-1] = Arr[i];
            count[j]--;
        }
        for(i = L,j = 0; i <= R; i++,j++)
            Arr[i] = bucket[j];
    }
    return;
}
