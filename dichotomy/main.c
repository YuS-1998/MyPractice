#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNum(int *, int, int, int *);//在一个有序数组中，找某个数是否存在
int findLeftNum(int *, int, int);//在一个有序数组中，找大于等于某个数的最左侧的位置
bool localMin(int *, int, int *, int *);//一个无序数组（但能确定相邻两个元素不相同）的局部最小值问题，找出一个就行

int main()
{
    int t1,t2;
    int index;
    int num;
    int Arr1[10] = {
        11, 23, 34, 44, 56, 66, 76, 85, 94, 98
    };
    int Arr2[10] = {
        1, 1, 1, 2, 2, 2, 2, 2, 3, 3
    };
    int Arr3[10] = {
        55, 36, 45, 95, 101, 52, 33, 45, 75, 98
    };

    printf("请输入你要找的数字：");

    scanf("%d",&t1);
    if(!findNum(Arr1, 10, t1, &index))
        printf("对不起，你要找的%d不在该数组中。\n",t1);
    else
        printf("找到了！你要找的%d在数组的第%d个\n",t1,index+1);

    printf("请输入你要找的数字：");
    scanf("%d",&t2);
    index = findLeftNum(Arr2, 10, t2);
    printf("找到了！你要找的最左边的%d在数组的第%d个\n",t2,index+1);

    if(!localMin(Arr3,10,&index,&num))
        printf("对不起！该数组中找不到局部最小值！\n");
    else
        printf("找到了！该数组中的一个局部最小值为第%d个元素%d\n",index+1,num);
    return 0;
}

bool findNum(int * Arr, int len, int num, int * pIndex)
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;
    while(low <= high)
    {
        if(Arr[mid] == num)
        {
            *pIndex = mid;
            return true;
        }
        else
        {
            if(Arr[mid] < num)//要找的数在mid的右边
            {
               low = mid+1;
               mid = (low+high)/2;
            }
            else//要找的数在mid的左边
            {
                high = mid-1;
                mid = (low+high)/2;
            }
        }
    }
    return false;
}

int findLeftNum(int * Arr, int len, int num)//与上一题最大的区别在于一定要找完，不会提前终止二分
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;
    int index;
    while(low <= high)
    {
        if(Arr[mid] >= num)
        {
            if(Arr[mid] == num)//这里说明在Arr[index]的左边还找到了要找的num，则更新index
                index = mid;
            high = mid-1;
            mid = (low+high)/2;
        }
        else//要找的数在mid的右边
        {
           low = mid+1;
           mid = (low+high)/2;
        }
    }
    return index;
}

bool localMin(int * Arr, int len, int * pIndex, int * pNum)
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;

    //首先判断第1个元素或者最后一个元素是不是局部最小值
    if(Arr[0] < Arr[1])
    {
        *pIndex = 0;
        *pNum = Arr[0];
        return true;
    }
    if(Arr[len-1] < Arr[len-2])
    {
        *pIndex = len-1;
        *pNum = Arr[len-1];
        return true;
    }
    while(low <= high)
    {
        if(Arr[mid] < Arr[mid-1] && Arr[mid] < Arr[mid+1])
        {
            *pIndex = mid;
            *pNum = Arr[mid];
            return true;
        }
        else
            if(Arr[mid] > Arr[mid-1])
            {
                high = mid-1;
                mid = (low+high)/2;
            }
            else
            {
                low = mid+1;
                mid = (low+high)/2;
            }
    }
    return false;
}
