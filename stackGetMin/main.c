#include <stdio.h>
#include <stdlib.h>
#include "GetMin.h"

int main()
{
    STACK S;
    initStack(&S);
    int val = getMin(&S);
    printf("��ջ����СԪ��Ϊ��%d\n",val);
    return 0;
}
