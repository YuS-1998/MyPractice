#include <stdio.h>
#include <stdlib.h>

int compare(int, int, int);
int Solution1(int *, int);
int Solution2(int *, int);

int main()
{
    int Arr[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water1 = Solution1(Arr, 12);
    printf("����������Խ�%d����ˮ��\n",water1);
    int water2 = Solution2(Arr, 12);
    printf("����������Խ�%d����ˮ��\n",water2);
    return 0;
}

int compare(int a, int b, int pattern)//pattern == 1�������С��һ����pattern == 0������ϴ��һ��
{
    if(1 == pattern)
    {
        if(a <= b)
            return a;
        else
            return b;
    }
    else
    {
        if(a >= b)
            return a;
        else
            return b;
    }
}

int Solution1(int * Arr, int len)
{
    int i;//ѭ������
    int LMax = Arr[0];//����һ��������ʾ��i��Ԫ�����Ԫ�ص����ֵ����ʼ��Ϊ����ĵ�һ��Ԫ��
    int R[len];//����һ����ԭ����ͬ���ȵ����飬������Ŵ��ұ߱�������i��Ԫ���ұ�Ԫ�ص����ֵ
    R[len-1] = Arr[len-1];//��ʼ��R��������ұ�һ��Ԫ����ԭ��������ұ�һ��Ԫ��
    int maxTemp = R[len-1];//����һ����ʱ����������ֵ
    int minTemp, temp;//����һ����ʱ���������Сֵ��һ����ʱ����
    int Water = 0;//����һ����ˮ��
    int waterTemp;//����һ����ʱˮ������

    //���ȱ��������R����
    for(i = len-1; i >= 0; i--)
    {
        maxTemp = compare(Arr[i], maxTemp, 0);//�������ֵ
        R[i] = maxTemp;
    }

    for(i = 1; i < len-1; i++)
    {
        minTemp = compare(LMax, R[i+1], 1);//���ȱȽϳ�Arr�����е�i��Ԫ�������������ֵ�н�С���Ǹ�
        temp = minTemp - Arr[i];
        waterTemp = compare(temp, 0, 0);
        Water += waterTemp;
        if(Arr[i] >= LMax)
            LMax = Arr[i];//����LMax
    }
    return Water;
}

int Solution2(int * Arr, int len)
{
    int * pL = &Arr[0];//����һ����ָ��ָ��������Ԫ��
    int * pR = &Arr[len-1];//����һ����ָ��ָ������ĩβԪ��
    int LMax = Arr[0];//����һ��������ʾĿǰ���Ԫ�ص����ֵ����ʼ��Ϊ��Ԫ�ص�ֵ
    int RMax = Arr[len-1];//����һ��������ʾĿǰ�ұ�Ԫ�ص����ֵ����ʼ��ΪĩԪ�ص�ֵ
    int Water = 0;//����һ��������¼�ܽ�ˮ��
    int waterTemp;

    while(pL != pR)
    {
        if(LMax <= RMax)
        {
            pL++;//��ָ�������ƶ�һ��
            waterTemp = compare(0, LMax-*pL, 0);
            LMax = compare(LMax, *pL, 0);//����LMax
            Water += waterTemp;
        }
        else
        {
            pR--;//��ָ�������ƶ�һ��
            waterTemp = compare(0, RMax-*pR, 0);
            RMax = compare(RMax, *pR, 0);//����RMax
            Water += waterTemp;
        }
    }
    return Water;
}
