#include <stdio.h>
#include <stdlib.h>
#include "GetMin.h"

int main()
{
    STACK S;
    initStack(&S);
    int val = getMin(&S);
    printf("该栈中最小元素为：%d\n",val);
    return 0;
}
