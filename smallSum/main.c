#include <stdio.h>
#include <stdlib.h>

int process(int *,int, int);
int merge(int *,int, int, int);

int main()
{
    //小和的意思是数组中某个元素左边所有比它小的元素的和
    //数组的小和就是所有的小和的和
    int Arr[5] = {1, 3, 4, 2, 5};
    int smallSum = process(Arr,0,4);
    printf("该数组的小和等于%d\n",smallSum);
    return 0;
}

//这里在实现时反向思考，计算某个元素右边所有比它大的元素的和
int process(int * Arr,int L, int R)
{
    if(L == R)
        return 0;
    int mid = L+(R-L)/2;
    return process(Arr,L,mid) + process(Arr,mid+1,R) + merge(Arr,L,mid,R);//返回值是左半边数组的小和加右半边数组的小和加把它们合并时候的小和
}

int merge(int * Arr,int L, int M, int R)
{
    int Help[R-L+1];
    int i = 0;
    int j;
    int p1 = L;
    int p2 = M+1;
    int res = 0;
    while(p1 <= M && p2 <= R)
    {
        if(Arr[p1] < Arr[p2])
        {
            res += (R-p2+1)*Arr[p1];//一定要排序，因为这样就可以用R减去当前的指针p2（因为排好序了，右边的元素一定比Arr[p2]大，也就比Arr[p1]大）来计算小和
            Help[i] = Arr[p1];
            p1++;
            i++;
        }
        else
        {
            Help[i] = Arr[p2];//这里注意与归并排序的一个很大的差别：当Arr[p1]=Arr[p2]时，被放到Help数组中的是右边的数（Arr[p2]）
            //因为Arr[p1]还没有计算完右半边数组中所有比它大的元素，不能移动指针
            p2++;
            i++;
        }
    }
    while(p1 <= M)
    {
        Help[i] = Arr[p1];
        p1++;
        i++;
    }
    while(p2 <= R)
    {
        Help[i] = Arr[p2];
        p2++;
        i++;
    }
    for(j = 0; j < i; j++)
        Arr[L+j] = Help[j];
    return res;
}
