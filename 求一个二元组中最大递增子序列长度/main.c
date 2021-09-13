#include <stdio.h>
#include <stdlib.h>

void sortArr(int *,int );//先排序
int lenArr(int *, int);//后计算最多可以摞多少个二元组

int main()
{
    int i;
    int Arr[8][2] = {
        {5,4}, {6,4}, {6,7}, {2,3}, {2,4}, {3,6}, {4,7}, {5,8}
    };
    int sizeArr = 8;
    printf("***************排序前***************\n");
    for(i = 0;i < sizeArr; i++)
    {
        printf("{%d,%d}\n",Arr[i][0],Arr[i][1]);
    }
    //int * p =
    sortArr(Arr, sizeArr);
    printf("***************排序后***************\n");
    for(i = 0;i < sizeArr; i++)
    {
        printf("{%d,%d}\n",Arr[i][0],Arr[i][1]);
    }
    int len = lenArr(Arr,sizeArr);
    printf("该二元组最多可以往上摞%d个！\n",len);
    return 0;
}

void sortArr(int * Arr, int sizeArr)//Arr是一个N*2的数组，sizeArr是其中二元数组的个数
{
    //先排序：按a升序，（a相同时）b降序的规则
    //Arr[i][0]表示第i个二元数组的a，Arr[i][1]表示第i个二元数组的b
    int i,j;//循环变量
    int t[2];//临时变量，用来临时存放二元数组
    int (*pArr)[2] = Arr;
    //冒泡排序
    for(i = 0; i < sizeArr-1; i++)//外圈控制比较轮数
    {
        for(j = 0; j < sizeArr-i-1; j++)//内圈控制每轮比较次数
        {
            if(*(*(pArr+j)+0) > *(*(pArr+j+1)+0))
            //if(*(*(Arr+j)+0) > *(*(Arr+j+1)+0))
            {
                t[0] = *(*(pArr+j)+0);
                t[1] = *(*(pArr+j)+1);
                *(*(pArr+j)+0) = *(*(pArr+j+1)+0);
                *(*(pArr+j)+1) = *(*(pArr+j+1)+1);
                *(*(pArr+j+1)+0) = t[0];
                *(*(pArr+j+1)+1) = t[1];
            }
            else
                if(*(*(pArr+j)+0) == *(*(pArr+j+1)+0))//如果两个二元组a相同
                {
                    if(*(*(pArr+j)+1) < *(*(pArr+j+1)+1))//比较b，b要降序排列
                    {
                        t[0] = *(*(pArr+j)+0);
                        t[1] = *(*(pArr+j)+1);
                        *(*(pArr+j)+0) = *(*(pArr+j+1)+0);
                        *(*(pArr+j)+1) = *(*(pArr+j+1)+1);
                        *(*(pArr+j+1)+0) = t[0];
                        *(*(pArr+j+1)+1) = t[1];
                    }
                }
        }
    }
    //return *pArr;
}

int lenArr(int * Arr, int sizeArr)
{
    //与上一个代码中的解法2类似
    int i,j;
    int (*pArr)[2] = Arr;
    int h[sizeArr];//这个h数组是用来存放二元组中的b元素的，处理方法与上一个代码中的解法2相同
    h[0] = *(*(pArr+0)+1);
    int len = 1;

    for(i = 1; i < sizeArr; i++)
    {
        int temp = 0;
        for(j = 0; j < len; j++)
        {
            if(*(*(pArr+i)+1) <= h[j])
            {
                h[j] = *(*(pArr+i)+1);
                temp++;
                break;
            }
        }
        if(0 == temp)
        {
            h[len] = *(*(pArr+i)+1);
            len++;
        }
    }
    return len;
}
