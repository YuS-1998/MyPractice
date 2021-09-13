#include <stdio.h>
#include <stdlib.h>

int area(int *, int);
int compare(int , int);

int main()
{
    int Arr[4] = {3, 4, 2, 5};
    int Area = area(Arr, 4);
    printf("������������Χ��������ֵΪ%d\n",Area);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int area(int * Arr, int sizeArr)
{
    int * pL = &Arr[0];//��ʼ��һ����ָ�룬ָ���������Ԫ��
    int * pR = &Arr[sizeArr-1];//��ʼ��һ����ָ�룬ָ�������ĩԪ��
    int max = 0;//����һ����������¼������ֵ

    while(pL != pR)
    {
        if(*pL <= *pR)
        {
            max = compare(*pL * (pR-pL-1), max);
            pL++;
        }
        else
        {
            max = compare(*pR * (pR-pL-1), max);
            pR--;
        }
    }
    return max;
}
