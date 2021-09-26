#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

int main()
{
//    int Arr[6] = {3,4,5,4,3,2};
//    int Max = maxSizeA(Arr, 6);
//    printf("该直方图能够围成的最大矩形的面积为%d\n",Max);

    int Matrix[5][6] = {
        {1,1,1,1,0,1},
        {1,1,0,1,1,0},
        {0,1,1,1,1,0},
        {1,1,1,1,1,1},
        {1,1,1,1,0,1}
    };
    int Max = maxSizeM(Matrix,5,6);
    printf("该矩阵中元素全为1的最大子矩阵大小为%d\n",Max);
    return 0;
}
