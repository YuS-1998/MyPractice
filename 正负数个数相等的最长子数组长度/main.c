#include <stdio.h>
#include <stdlib.h>

int compare(int, int);
int Traverse(int *, int, int);
int MaxLen2(int *, int);

int main()
{
    int Arr[8] = {3, -2, 1, -6, 4, 3, -2, 3};
    int len2 = MaxLen2(Arr, 8);
    printf("��������������������������븺��������ȵ�������鳤��Ϊ%d\n",len2);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int Traverse(int * Arr, int L, int R)
{
    int i;
    for(i = L; i < R+1; i++)
    {
        printf("%d ",Arr[i]);
    }
    printf("\n");
}

int MaxLen2(int * Arr, int sizeArr)
{
    int i;//ѭ������
    int L = 0;//��ָ��
    int R = sizeArr-1;//��ָ��
    int P[sizeArr];//��һ�������¼��ǰԪ���ұߣ�������ǰԪ�أ����м����������������ұ�����
    int N[sizeArr];//��һ�������¼��ǰԪ����ߣ�������ǰԪ�أ����м����������������������
    int temp = 0;//��ʱ����
    int PTemp = 0;
    int NTemp = 0;//����������ʱ������������������¼����ָ�����ƻ���ָ�����ƴ����������������ı仯

    //���P,N��������
    for(i = 0; i < sizeArr; i++)
    {
        if(Arr[i] > 0)
            temp++;
        P[i] = temp;
    }
    temp = 0;//������ʱ����
    for(i = sizeArr-1; i >= 0; i--)
    {
        if(Arr[i] < 0)
            temp++;
        N[i] = temp;
    }

    //����������������ָ�룬��Ա������Ƚϵ�ǰ��ָ��ָ���Ԫ���ұߵĸ�����������ָ��ָ���Ԫ����ߵ�������������P[R]��N[L]��
    //��P[R]��ʱ��˵���������ˣ�Ҫ�����������е���������Arr[L]��Arr[R]������ͬ������ָ�����ƣ������Ų�ͬ�����ƶ��������Ǳ�ָ�롣
    //ע�⣬�ٸ����ӣ����Arr[L]Ϊ����Arr[R]Ϊ��������ָ�����ƣ�����ʱ�������ڵ���������������1������P���鶼Ҫ��1��
    //��N[L]��ʱͬ��
    //���ϸ�������ָ�룬ֱ����ǰ��ָ��ָ���Ԫ���ұߵĸ�����������ָ��ָ���Ԫ����ߵ������������ʱ��ֹͣ���£��õ���ʱ������ĳ��ȣ���Ϊ����
    while(P[R]-PTemp != N[L]-NTemp)
    {
        if(P[R]-PTemp > N[L]-NTemp)
        {
            if(Arr[R] > 0)
                R--;
            else
            {
                if(Arr[L] > 0)
                {
                    L++;
                    PTemp++;
                }
                else
                {
                    R--;
                    NTemp++;
                }
            }
        }
        else
        {
            if(Arr[L] < 0)
                L++;
            else
            {
                if(Arr[R] < 0)
                {
                    R--;
                    NTemp++;
                }
                else
                {
                    L++;
                    PTemp++;
                }
            }
        }
        Traverse(Arr,L,R);
    }
    return R-L+1;
}
