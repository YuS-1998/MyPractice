#include <stdio.h>
#include <stdlib.h>

int area(int *, int);
int compare(int , int);

int main()
{
    int Arr[4] = {3, 4, 2, 5};
    int Area = area(Arr, 4);
    printf("任意两个柱子围成面积最大值为%d\n",Area);
    return 0;
}

int compare(int a, int b)//输出较大的一个
{
    if(a >= b)
        return a;
    else
        return b;
}

int area(int * Arr, int sizeArr)
{
    int * pL = &Arr[0];//初始化一个左指针，指向数组的首元素
    int * pR = &Arr[sizeArr-1];//初始化一个右指针，指向数组的末元素
    int max = 0;//定义一个变量，记录面积最大值

    while(pL != pR)
    {
        if(*pL <= *pR)
        {
            max = compare(*pL * (pR-pL-1), max);
            pL++;
        }
        else
        {
            max = compare(*pR * (pR-pL-1), max);
            pR--;
        }
    }
    return max;
}
