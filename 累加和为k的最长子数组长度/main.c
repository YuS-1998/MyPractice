#include <stdio.h>
#include <stdlib.h>

int MaxLen(int *, int , int );
int compare(int , int );
//int Summary(int *,int *);

int main()
{
    //int Arr[5] = {1, 2, 1, 1, 1};
    int Arr[9] = {2, 3, 1, 1, 1, 1, 1, 3, 2};
    int len = MaxLen(Arr, 9, 5);
    printf("累加和为5的最长子数组的长度为：%d\n",len);
    return 0;
}

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

//int Summary(int *pL, int *pR)//计算两个指针中间包括的子数组的累加和
//{
//    int * p1 = pL;
//    int * p2 = pR;//定义两个临时的变量
//    int sum = 0;
//
//    while(p1 != p2)
//    {
//        sum += *p1;
//        p1++;
//    }
//    sum += *p2;
//    return sum;
//}

int MaxLen(int * Arr, int len, int k)
{
    int i;//循环变量
    int *pL = &Arr[0];//定义左指针，指向数组首地址
    int *pR = &Arr[0];//定义右指针，初始化为数组首地址
    int maxLen = 0;//定义最长子数组长度
    int sum = Arr[0];//记录当前子数组的和

    for(i = 0; ; i++)
    {
        //当满足右指针移到最后一个元素，同时当前子数组的累加和小于等于k（当累加和小于等于k时，此时右指针已经没法右移了，累加和没法增加，左指针再向右移，累加和又会变小，没有意义），
        //或者最后左右指针都指向末元素时结束循环
        //sum = Summary(pL, pR);
        printf("第%d次循环的累加和为%d\n",i+1,sum);
        if((sum <= k && pR == &Arr[len-1]) || (pL == &Arr[len-1] && pR == &Arr[len-1]))
        {
            maxLen = compare(maxLen, pR-pL+1);
            return maxLen;
        }
        else
        {
            if(sum == k)
                maxLen = compare(maxLen, pR-pL+1);//当满足子数组累加和等于k时，更新最大子数组长度
            if(sum <= k)
            {
                pR++;
                sum += *pR;//在累加和中加上新加的数字
            }

            else
            {
                sum -= *pL;//在累加和中去掉左指针此时指向的元素
                pL++;
            }

        }
    }
}
