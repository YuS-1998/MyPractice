#include <stdio.h>
#include <stdlib.h>
#include "BTNode.h"

int main()
{
    PNode pRoot = CreateBTree();
    int h = numHeight(pRoot);
    printf("����ȫ�������Ĳ���Ϊ%d\n",h);
    int num = numNode(pRoot,h);
    printf("����ȫ�������Ľڵ���Ϊ%d\n",num);
    return 0;
}
