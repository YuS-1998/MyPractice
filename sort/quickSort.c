#include "Sort.h"

int GetSrand(int * arr,int len)
{
     srand(time(0));
     return arr[rand()%len];
}

void quickSort1(int * Arr, int L, int R)//快排1.0版本：只分小于等于区和大于区，每次递归只能排好作为划分标准的那个数（Arr[R]）
{
    if(L < R)
    {
        int less;
        partition1(Arr,L,R,&less);
        quickSort1(Arr,L,less-1);//小于等于区快排
        quickSort1(Arr,less+1,R);//大于区快排
    }
}

void quickSort2(int * Arr, int L, int R)//快排2.0版本：划分小于区，等于区，大于区，这样每次递归等于区的数的位置就固定了，会比1.0版本每次多排好一些数，更快一些
{
    if(L < R)
    {
        int b1,b2;
        partition2(Arr,L,R,&b1,&b2);
        quickSort2(Arr,L,b1-1);//小于区快排
        quickSort2(Arr,b2+1,R);//大于区快排
    }
}
//前两个版本的复杂度都是O(N^2)

void quickSort3(int * Arr, int L, int R)//快排3.0版本：在2.0版本的基础上，每次作为划分标准的数不再是固定的Arr[R]了，而是随机的一个数，这样复杂度就变成了O(NlogN)
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int r = GetSrand(a,R-L+1);
    if(L < R)
    {
        int b1,b2;
        swap(Arr,L+r,R);//用随机选出来的数做划分值，将它交换到数组的最后
        partition2(Arr,L,R,&b1,&b2);
        quickSort3(Arr,L,b1-1);//小于区快排
        quickSort3(Arr,b2+1,R);//大于区快排
    }
}

void partition1(int * Arr, int L, int R, int * pLess)
{
    int less = L-1;//小于等于区的右边界
    while(L <= R)//L表示当前元素位置
    {//道理同荷兰国旗基础问题
        if(Arr[L] <= Arr[R])
        {
            swap(Arr,L,less+1);
            less++;
            L++;
        }
        else
            L++;
    }
    *pLess = less;
    return;
}

void partition2(int * Arr, int L, int R, int * pb1, int * pb2)
{
    int less = L-1;//小于区的右边界
    int more = R;//大于区的左边界，Arr[R]为划分值
    while(L < more)//L表示当前元素位置
    {//道理同荷兰国旗问题
        if(Arr[L] < Arr[R])
            swap(Arr,++less,L++);
        else
        {
            if(Arr[L] > Arr[R])
                swap(Arr,--more,L);
            else
                L++;
        }
    }
    swap(Arr,R,more);//交换Arr[R]和Arr[more]，使划分值也来到等于区
    *pb1 = less+1;//等于区的左边界
    *pb2 = more;//等于区右边界
    return;
}
