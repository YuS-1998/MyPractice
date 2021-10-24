#include <stdio.h>
#include <stdlib.h>

void printOddTimesNum1(int *, int);
void printOddTimesNum2(int *, int);

int main()
{
    int Arr1[11] = {
        1, 2, 3, 4, 2, 5, 5, 1, 3, 4, 5
    };
    printOddTimesNum1(Arr1, 11);
    int Arr2[12] = {
        1, 2, 3, 4, 2, 5, 5, 1, 3, 4, 5, 2
    };
    printOddTimesNum2(Arr2, 12);
    return 0;
}

//异或：0^N=N,N^N=0；满足交换律和结合律；一堆数字异或不论顺序结果是一样的
//一个数字出现奇数次，异或后等于原数字；出现偶数次，异或后等于0
//用异或交换两个数字：a = a^b; b = a^b; a = a^b;
//异或相当于无进位二进制相加

//一个数组中只有一种数字出现奇数次，其他的都出现偶数次，找出出现奇数次的数字
void printOddTimesNum1(int * Arr, int len)
{
    int i;
    int eor = 0;
    for(i = 0; i < len; i++)
        eor ^= Arr[i];
    printf("这个数组中出现奇数次的数字是%d\n",eor);
    return;
}

//一个数组中只有两种数字出现奇数次，其他的都出现偶数次，找出出现奇数次的数字
void printOddTimesNum2(int * Arr, int len)
{
    int i;
    int eor = 0;
    int eor2 = 0;
    for(i = 0; i < len; i++)
        eor ^= Arr[i];//此时eor等于两个出现奇数次的数字异或的结果
    int rightone = eor & (~eor+1);//用这个方法可以提取eor最右边的一个1（将eor看成二进制数）
    for(i = 0; i < len; i++)
    {
        if(Arr[i] & rightone == 1)//将Arr的数字分成两组，一组是在这一位上是1的，一组是这一位上是0的（两个出现奇数次的数字一定分属两个组）
            eor2 ^= Arr[i];//用这种方法找出其中一个出现了奇数次的数字
    }
    printf("两种出现奇数次的数字分别是%d和%d\n",eor2,eor2^eor);
    return;
}
