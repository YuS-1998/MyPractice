#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxSize.h"

int main()
{
//    int Arr[6] = {3,4,5,4,3,2};
//    int Max = maxSizeA(Arr, 6);
//    printf("��ֱ��ͼ�ܹ�Χ�ɵ������ε����Ϊ%d\n",Max);

    int Matrix[5][6] = {
        {1,1,1,1,0,1},
        {1,1,0,1,1,0},
        {0,1,1,1,1,0},
        {1,1,1,1,1,1},
        {1,1,1,1,0,1}
    };
    int Max = maxSizeM(Matrix,5,6);
    printf("�þ�����Ԫ��ȫΪ1������Ӿ����СΪ%d\n",Max);
    return 0;
}
