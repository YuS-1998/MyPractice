#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int i,t;
    int val;
    STACK S;
    initStack(&S);
    for(i = 0; i < 6; i++)
    {
        printf("请输入你要压栈的元素：");
        scanf("%d",&t);
        pushStack(&S,t);
    }
    printf("原始栈为：");
    traverseStack(&S);

//    val = getAndRemoveLast(&S);
//    printf("得到的栈底元素为：%d，此时栈为：",val);
//    traverseStack(&S);

    reverseStack(&S);
    printf("反转后的栈为：");
    traverseStack(&S);
    return 0;
}
