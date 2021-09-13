#include <stdio.h>
#include <stdlib.h>

int maxSum(int *, int);

int main()
{
    int Arr[8] = {3, -2, 1, -6, 4, 3, -2, 3};
    int Max = maxSum(Arr, 8);
    printf("两个子数组的最大累加和的和为：%d\n",Max);
    return 0;
}

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSum(int * Arr, int len)
{
    int i;//循环变量
    int Lcur = Arr[0];//用Lcur记录从左遍历的当前累加和，初始化为原数组的首元素
    int Lres = Arr[0];//用一个变量记录0-i元素的子数组的最大累加和，初始化为原数组的首元素
    int R[len];//用一个数组记录i+1-N元素的子数组的最大累加和（从右到左遍历）
    R[len-1] = Arr[len-1];//R数组的末元素初始化为原数组的末元素
    int Rcur = R[len-1];//Rcur记录当前的累加和，初始化为R数组的末元素
    int Rres = R[len-1];//Rres记录最大累加和，初始化为R数组的末元素
    int res;//用res变量记录两个子数组最大的累加和

    if(NULL == Arr || len < 2)
        return 0;

    //先从右往左遍历，生成数组R
    for(i = len-2; i >= 0; i--)
    {
        Rcur = compare(0, Rcur);//若cur小于0，则将cur清零
        Rcur += Arr[i];//计算当前累加和
        Rres = compare(Rcur, Rres);//更新最大累加和
        R[i] = Rres;//用R数组记录当前最大累加和
    }
    res = Lres + R[1];

    for(i = 1; i < len; i++)
    {
       res = compare(res, Lres + R[i]);//两个子数组最大的累加和等于0-i元素和i+1-N元素的子数组最大的累加和的和
       //更新Lres
       Lcur = compare(0, Lcur);
       Lcur += Arr[i];
       Lres = compare(Lcur, Lres);
    }

    return res;
}
