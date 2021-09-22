#include <stdio.h>
#include <stdlib.h>

int compare(int , int );
int maxSize(int *, int ,int );

int main()
{
    int Matrix[3][3] = {{1,3,5},{-3,5,-2},{9,1,-3}};
    int Res = maxSize(Matrix, 3, 5);
    printf("这个矩阵的累加和小于等于9的最大子矩阵的大小为%d\n",Res);
    return 0;
}

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSize(int * Matrix, int n, int k)
{
    int i,j,p,q;//循环变量
    int Max = 0;//最大子矩阵大小
    int Arr[n];//用一个数组记录按列累加的和
    int h[n];//用一个数组首先记录遍历到数组的第j个元素时的累加和
    int (*pMatrix)[n] = Matrix;


    //与上一题大思维相同，同样考虑第1行，第1，2行，第1，2，3行……第2行，第2，3行，……以此类推
    //在将累加和缩小到数组考虑时，可以参考第二章中的累加和小于等于k的最大子数组长度的方法
    //此处提供一个新的方法：
    //用一个数组首先记录遍历到数组的第j个元素时的累加和，得到一个长度为n的数组h
    //第二步当遍历到原数组的第j个元素时，找到h数组中第j个元素之前第一个大于等于h[j]-k的数，输出两个元素之间的距离
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Arr[j] = 0;//将Arr初始化为全零数组
        }

        for(j = i; j < n; j++)
        {
            for(p = 0; p < n; p++)
            {
                Arr[p] += *(*(pMatrix+j)+p);//累加上第j行的元素
                printf("%d ",Arr[p]);
            }
            printf("\n");

            h[0] = Arr[0];//h数组的首元素初始化为Arr数组的首元素
            for(p = 1; p < n; p++)
            {
                h[p] = h[p-1] + Arr[p];//累加得到数组h
                printf("%d ",h[p]);
            }
            printf("\n");

            for(p = 0; p < n; p++)
            {
                int temp = 0;
                for(q = 0; q <= p; q++)
                {
                    if(h[q] >= h[p] - k)
                    {
                        if(p == q && h[q] >= k)
                            temp = 0;
                        else
                        {
                            temp = p - q + 1;//找到第一个累加和大于等于h[p]-k的元素标签，求两个元素之间的距离
                            break;
                        }
                    }
                }
                printf("%d ",temp);
                Max = compare(Max, temp*(j-i+1));
                printf("%d\n",Max);
            }
        }
    }
    return Max;
}
