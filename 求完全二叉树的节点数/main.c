#include <stdio.h>
#include <stdlib.h>
#include "BTNode.h"

int main()
{
    PNode pRoot = CreateBTree();
    int h = numHeight(pRoot);
    printf("该完全二叉树的层数为%d\n",h);
    int num = numNode(pRoot,h);
    printf("该完全二叉树的节点数为%d\n",num);
    return 0;
}
