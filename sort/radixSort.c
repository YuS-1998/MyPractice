#include "Sort.h"

int getDigit(int num, int d)//要取出num的第d位（从右往左算）
{
    int b = num / pow(10,d-1);
    int a = b % 10;
    return a;
}

void radixSort(int * Arr, int L, int R)
{
    int i,j,d;
    int max = Arr[L];
    int digit = 0;//数组中的元素最多有digit位
    int radix = 10;//表示每一位上的数字都只有10种可能（0~9）
    int bucket[R-L+1];//有几个数就要准备几个辅助空间
    //先得到数组中最大的数字有几位，即数组中的元素最多有几位
    for(i = L+1; i <= R; i++)
        max = Arr[i] > max ? Arr[i] : max;
    while(max != 0)
    {
        digit++;
        max /= 10;
    }

    for(d = 1; d <= digit; d++)//有几位就要进出桶几次
    {
        int count[radix];
        for(i = 0; i < radix; i++)
            count[i] = 0;
        for(i = L; i <= R; i++)
        {
            j = getDigit(Arr[i],d);
            count[j]++;//这里count[j]表示第d位是j的数字有几个
        }
        for(i = 1; i < radix; i++)
            count[i] += count[i-1];//这里count[i]表示第d位小于等于i的数字有几个
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
