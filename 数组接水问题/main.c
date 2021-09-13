#include <stdio.h>
#include <stdlib.h>

int compare(int, int, int);
int Solution1(int *, int);
int Solution2(int *, int);

int main()
{
    int Arr[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water1 = Solution1(Arr, 12);
    printf("这个容器可以接%d格子水！\n",water1);
    int water2 = Solution2(Arr, 12);
    printf("这个容器可以接%d格子水！\n",water2);
    return 0;
}

int compare(int a, int b, int pattern)//pattern == 1：输出较小的一个；pattern == 0：输出较大的一个
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
    int i;//循环变量
    int LMax = Arr[0];//定义一个变量表示第i个元素左边元素的最大值，初始化为数组的第一个元素
    int R[len];//定义一个与原数组同长度的数组，用来存放从右边遍历，第i个元素右边元素的最大值
    R[len-1] = Arr[len-1];//初始化R数组的最右边一个元素是原数组的最右边一个元素
    int maxTemp = R[len-1];//定义一个临时变量存放最大值
    int minTemp, temp;//定义一个临时变量存放最小值和一个临时变量
    int Water = 0;//定义一个总水量
    int waterTemp;//定义一个临时水量变量

    //首先遍历，完成R数组
    for(i = len-1; i >= 0; i--)
    {
        maxTemp = compare(Arr[i], maxTemp, 0);//更新最大值
        R[i] = maxTemp;
    }

    for(i = 1; i < len-1; i++)
    {
        minTemp = compare(LMax, R[i+1], 1);//首先比较出Arr数组中第i个元素左右两边最大值中较小的那个
        temp = minTemp - Arr[i];
        waterTemp = compare(temp, 0, 0);
        Water += waterTemp;
        if(Arr[i] >= LMax)
            LMax = Arr[i];//更新LMax
    }
    return Water;
}

int Solution2(int * Arr, int len)
{
    int * pL = &Arr[0];//定义一个左指针指向数组首元素
    int * pR = &Arr[len-1];//定义一个右指针指向数组末尾元素
    int LMax = Arr[0];//定义一个变量表示目前左边元素的最大值，初始化为首元素的值
    int RMax = Arr[len-1];//定义一个变量表示目前右边元素的最大值，初始化为末元素的值
    int Water = 0;//定义一个变量记录总接水量
    int waterTemp;

    while(pL != pR)
    {
        if(LMax <= RMax)
        {
            pL++;//左指针向右移动一个
            waterTemp = compare(0, LMax-*pL, 0);
            LMax = compare(LMax, *pL, 0);//更新LMax
            Water += waterTemp;
        }
        else
        {
            pR--;//右指针向左移动一个
            waterTemp = compare(0, RMax-*pR, 0);
            RMax = compare(RMax, *pR, 0);//更新RMax
            Water += waterTemp;
        }
    }
    return Water;
}
