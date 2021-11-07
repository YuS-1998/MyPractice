#include <stdio.h>
#include <stdlib.h>

void swap(int *,int,int);//交换数组中的第i个和第j个元素
void traverse(int *,int);//遍历显示数组
void DutchFlag1(int *, int, int);//基础：给定一个数组和一个数，要求比该数小于等于的元素都放数组左半边，大的都放右半边
void DutchFlag2(int *, int, int);//进阶：在上面的基础上，将等于给定数的元素放中间

int main()
{
    int Arr1[10] = {
        1, 6, 7, 4, 9, 3, 2, 8, 5, 0
    };
    int Arr2[10] = {
        1, 6, 7, 4, 5, 3, 2, 8, 9, 5
    };
    printf("****************基础版****************\n");
    printf("归类前：");
    traverse(Arr1,10);
    printf("\n");
    DutchFlag1(Arr1,10,5);
    printf("归类后：");
    traverse(Arr1,10);
    printf("\n");

    printf("****************进阶版****************\n");
    printf("归类前：");
    traverse(Arr2,10);
    printf("\n");
    DutchFlag2(Arr2,10,5);
    printf("归类后：");
    traverse(Arr2,10);
    return 0;
}

void swap(int * Arr,int i,int j)
{
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
    return;
}

void traverse(int * Arr,int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%d ",Arr[i]);
    return;
}

void DutchFlag1(int * Arr, int len, int num)
{
    int i = 0;
    int flag = -1;//作为小于等于区的边界

    while(i <= len)
    {
        if(Arr[i] <= num)
        {
            swap(Arr,i,flag+1);//如果当前数小于等于给定的num，把当前数和小于等于区的边界的下一个数交换
            flag++;//再将小于等于区向右扩展一位
            i++;
        }
        else
            i++;//如果当前数大于给定的num，则继续考虑下一个元素
//        traverse(Arr,10);
//        printf("\n");
    }
    return;
}

void DutchFlag2(int * Arr, int len, int num)
{
    int i = 0;
    int flagL = -1;//作为小于区的右边界
    int flagR = len;//作为大于区的左边界

    while(i < flagR)
    {
        if(Arr[i] < num)
        {
            swap(Arr,i,flagL+1);//如果当前数小于给定的num，把当前数和小于等于区的边界的下一个数交换
            flagL++;//再将小于区向右扩展一位
            i++;
        }
        else
        {
            if(Arr[i] == num)
                i++;//如果当前数等于给定的num，则继续考虑下一个元素
            else
            {
                swap(Arr,i,flagR-1);//如果当前数大于给定的num，把当前数和大于等于区的边界的前一个数交换
                flagR--;//注意这里仅仅将大于区向前扩展一位，而不移动i，因为交换过来的数还没有被分类过，移动了i就会错过这个数
            }
        }
//        traverse(Arr,10);
//        printf("\n");
    }
    return;
}
