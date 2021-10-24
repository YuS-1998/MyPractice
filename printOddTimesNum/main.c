#include <stdio.h>
#include <stdlib.h>

void printOddTimesNum1(int *, int);
void printOddTimesNum2(int *, int);

int main()
{
    int Arr1[11] = {
        1, 2, 3, 4, 2, 5, 5, 1, 3, 4, 5
    };
    printOddTimesNum1(Arr1, 11);
    int Arr2[12] = {
        1, 2, 3, 4, 2, 5, 5, 1, 3, 4, 5, 2
    };
    printOddTimesNum2(Arr2, 12);
    return 0;
}

//���0^N=N,N^N=0�����㽻���ɺͽ���ɣ�һ�����������˳������һ����
//һ�����ֳ��������Σ��������ԭ���֣�����ż���Σ��������0
//����򽻻��������֣�a = a^b; b = a^b; a = a^b;
//����൱���޽�λ���������

//һ��������ֻ��һ�����ֳ��������Σ������Ķ�����ż���Σ��ҳ����������ε�����
void printOddTimesNum1(int * Arr, int len)
{
    int i;
    int eor = 0;
    for(i = 0; i < len; i++)
        eor ^= Arr[i];
    printf("��������г��������ε�������%d\n",eor);
    return;
}

//һ��������ֻ���������ֳ��������Σ������Ķ�����ż���Σ��ҳ����������ε�����
void printOddTimesNum2(int * Arr, int len)
{
    int i;
    int eor = 0;
    int eor2 = 0;
    for(i = 0; i < len; i++)
        eor ^= Arr[i];//��ʱeor�����������������ε��������Ľ��
    int rightone = eor & (~eor+1);//���������������ȡeor���ұߵ�һ��1����eor���ɶ���������
    for(i = 0; i < len; i++)
    {
        if(Arr[i] & rightone == 1)//��Arr�����ֳַ����飬һ��������һλ����1�ģ�һ������һλ����0�ģ��������������ε�����һ�����������飩
            eor2 ^= Arr[i];//�����ַ����ҳ�����һ�������������ε�����
    }
    printf("���ֳ��������ε����ֱַ���%d��%d\n",eor2,eor2^eor);
    return;
}
