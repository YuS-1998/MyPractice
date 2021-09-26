#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSizeA(int * Arr, int len)
{
    int i;
    STACK S;//定义一个栈
    int val;//用一个变量接收出栈的元素
    int Max = 0;//用来记录最大面积值
    initStack(&S);//初始化这个栈
    pushStack(&S,0);//首先将0压入栈内（压入的都是数组元素的标签）
    Arr[len] = 0;//给Arr扩展最后一位为零，这样方便结算整个数组

    for(i = 1; i <= len; i++)
    {
        while(Arr[i] <= Arr[S.pTop->data] && !emptyStack(&S))//如果数组当前元素小于等于栈中栈顶元素的的话，将当前栈顶元素出栈，并结算（用右边界减左边界的距离乘以出栈的栈顶元素）
        {
            popStack(&S,&val);
            if(emptyStack(&S))
            {
                Max = compare(Max,i*Arr[val]);//当前右边界为i，左边界为-1
                pushStack(&S,i);
                break;
            }

            else
                Max = compare(Max,(i-(S.pTop->data)-1)*Arr[val]);//当前右边界为i，左边界为栈顶节点的下一个节点（即现在的栈顶节点）
        }
        if(Arr[i] > Arr[S.pTop->data])//如果数组当前元素比栈中栈顶元素大的话，直接将当前元素压入栈中
            pushStack(&S,i);
    }
    return Max;
}

int maxSizeM(int * Matrix, int m, int n)//求矩阵m*n的矩阵列方向上连续1的个数（一行中的各个元素表示当前位置向上有多少个连续的1）
{
    int i,j;
    int Arr[n];
    int Max = 0;//为最后的结果
    int MaxTemp;//用做每行结算全为1的子矩阵大小时的最大值
    int (*pMatrix)[n] = Matrix;

    //初始化Arr[n]（为1的记为1，为0的记为0）
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
                Arr[j] += 1;//若仍为1，则计数+1
            else
                Arr[j] = 0;//若为0（即没有连续的1），则计数清零
        }
        MaxTemp = maxSizeA(Arr,n);
        Max = compare(MaxTemp,Max);
    }
    return Max;
}
