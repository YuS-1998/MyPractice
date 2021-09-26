#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSizeA(int * Arr, int len)
{
    int i;
    STACK S;//����һ��ջ
    int val;//��һ���������ճ�ջ��Ԫ��
    int Max = 0;//������¼������ֵ
    initStack(&S);//��ʼ�����ջ
    pushStack(&S,0);//���Ƚ�0ѹ��ջ�ڣ�ѹ��Ķ�������Ԫ�صı�ǩ��
    Arr[len] = 0;//��Arr��չ���һλΪ�㣬�������������������

    for(i = 1; i <= len; i++)
    {
        while(Arr[i] <= Arr[S.pTop->data] && !emptyStack(&S))//������鵱ǰԪ��С�ڵ���ջ��ջ��Ԫ�صĵĻ�������ǰջ��Ԫ�س�ջ�������㣨���ұ߽����߽�ľ�����Գ�ջ��ջ��Ԫ�أ�
        {
            popStack(&S,&val);
            if(emptyStack(&S))
            {
                Max = compare(Max,i*Arr[val]);//��ǰ�ұ߽�Ϊi����߽�Ϊ-1
                pushStack(&S,i);
                break;
            }

            else
                Max = compare(Max,(i-(S.pTop->data)-1)*Arr[val]);//��ǰ�ұ߽�Ϊi����߽�Ϊջ���ڵ����һ���ڵ㣨�����ڵ�ջ���ڵ㣩
        }
        if(Arr[i] > Arr[S.pTop->data])//������鵱ǰԪ�ر�ջ��ջ��Ԫ�ش�Ļ���ֱ�ӽ���ǰԪ��ѹ��ջ��
            pushStack(&S,i);
    }
    return Max;
}

int maxSizeM(int * Matrix, int m, int n)//�����m*n�ľ����з���������1�ĸ�����һ���еĸ���Ԫ�ر�ʾ��ǰλ�������ж��ٸ�������1��
{
    int i,j;
    int Arr[n];
    int Max = 0;//Ϊ���Ľ��
    int MaxTemp;//����ÿ�н���ȫΪ1���Ӿ����Сʱ�����ֵ
    int (*pMatrix)[n] = Matrix;

    //��ʼ��Arr[n]��Ϊ1�ļ�Ϊ1��Ϊ0�ļ�Ϊ0��
    for(i = 0; i < n; i++)
    {
        if(1 == *(*(pMatrix+0)+i))
            Arr[i] = 1;
        else
            Arr[i] = 0;
    }
    MaxTemp = maxSizeA(Arr,n);
    Max = compare(MaxTemp,Max);

    for(i = 1; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(1 == *(*(pMatrix+i)+j))
                Arr[j] += 1;//����Ϊ1�������+1
            else
                Arr[j] = 0;//��Ϊ0����û��������1�������������
        }
        MaxTemp = maxSizeA(Arr,n);
        Max = compare(MaxTemp,Max);
    }
    return Max;
}
