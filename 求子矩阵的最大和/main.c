#include <stdio.h>
#include <stdlib.h>

int maxSum(int *, int );
int compare(int , int );

int main()
{
    int Matrix[3][3] = {{1,3,5},{-3,5,-2},{9,1,-3}};
    int Res = maxSum(Matrix, 3);
    printf("这个矩阵的子矩阵的最大和为%d\n",Res);
    return 0;
}

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSum(int * Matrix, int n)//Matrix是一个n*n的矩阵
{
    //假设有一个5*5的矩阵，算法流程为：
    //首先依次计算第1行，第1、2行，第1，2，3行……第2行，第2，3行……第4，5行，第5行子矩阵按列将元素相加得到数组
    //再用求子数组最大累加和的方法，求得最大的累加和。
    //最后得到的结果就是要求的子矩阵的最大和

    int i, j, k;//循环变量
    int Res = 0;//用来记录最后结果的
    int cur;//用来记录求子数组最大累加和时的目前的累加和
    int resTemp;//临时变量，用来记录每次求子数组的最大累加和的结果
    int Arr[n];//用来记录子矩阵按列将元素相加得到的数组
    int (*pMatrix)[n] = Matrix;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Arr[j] = 0;//每次循环先将Arr[n]初始化为全零数组
        }

        for(j = i; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                Arr[k] += *(*(pMatrix+j)+k);//每次多累加上一行，得到当前子矩阵按列相加得到的数组
            }

            cur =  resTemp = Arr[0];//将cur与resTemp都初始化为Arr的第一个元素
            for(k = 1; k < n; k++)
            {
                cur += Arr[k];
                resTemp = compare(cur, resTemp);//比较更新最大累加和
                cur = compare(0, cur);//若此时累加和小于0，则将累加和清零
            }
            Res = compare(resTemp, Res);//比较更新子矩阵最大和
        }
    }
    return Res;
}
