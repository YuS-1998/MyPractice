#include <stdio.h>
#include <stdlib.h>

int compare(int, int);
int Traverse(int *, int, int);
int MaxLen2(int *, int);

int main()
{
    int Arr[8] = {3, -2, 1, -6, 4, 3, -2, 3};
    int len2 = MaxLen2(Arr, 8);
    printf("这个数组中所有子数组中正数与负数个数相等的最长子数组长度为%d\n",len2);
    return 0;
}

int compare(int a, int b)//输出较大的一个
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
    int i;//循环变量
    int L = 0;//左指针
    int R = sizeArr-1;//右指针
    int P[sizeArr];//用一个数组记录当前元素右边（包括当前元素）共有几个正数（从左至右遍历）
    int N[sizeArr];//用一个数组记录当前元素左边（包括当前元素）共有几个负数（从右至左遍历）
    int temp = 0;//临时变量
    int PTemp = 0;
    int NTemp = 0;//定义两个临时变量，这里是用来记录当左指针右移或右指针左移带来的正负数个数的变化

    //完成P,N两个数组
    for(i = 0; i < sizeArr; i++)
    {
        if(Arr[i] > 0)
            temp++;
        P[i] = temp;
    }
    temp = 0;//重置临时变量
    for(i = sizeArr-1; i >= 0; i--)
    {
        if(Arr[i] < 0)
            temp++;
        N[i] = temp;
    }

    //操作：用两个左右指针，相对遍历。比较当前左指针指向的元素右边的负数个数和右指针指向的元素左边的正数个数（及P[R]和N[L]）
    //当P[R]大时，说明正数多了，要减少子数组中的正数。若Arr[L]和Arr[R]符号相同，则将右指针左移；若符号不同，则移动正数的那边指针。
    //注意，举个例子，如果Arr[L]为正，Arr[R]为负，则左指针右移，但此时子数组内的正数个数就少了1个，及P数组都要减1。
    //当N[L]大时同理。
    //不断更新两个指针，直到当前左指针指向的元素右边的负数个数和右指针指向的元素左边的正数个数相等时，停止更新，得到此时子数组的长度，即为所求。
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
