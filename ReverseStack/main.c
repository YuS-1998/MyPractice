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
        printf("��������Ҫѹջ��Ԫ�أ�");
        scanf("%d",&t);
        pushStack(&S,t);
    }
    printf("ԭʼջΪ��");
    traverseStack(&S);

//    val = getAndRemoveLast(&S);
//    printf("�õ���ջ��Ԫ��Ϊ��%d����ʱջΪ��",val);
//    traverseStack(&S);

    reverseStack(&S);
    printf("��ת���ջΪ��");
    traverseStack(&S);
    return 0;
}
