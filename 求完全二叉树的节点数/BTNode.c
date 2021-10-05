#include "BTNode.h"

PNode CreateBTree()
{
    PNode pA = (PNode)malloc(sizeof(NODE));
    PNode pB = (PNode)malloc(sizeof(NODE));
    PNode pC = (PNode)malloc(sizeof(NODE));
    PNode pD = (PNode)malloc(sizeof(NODE));
    PNode pE = (PNode)malloc(sizeof(NODE));
    PNode pF = (PNode)malloc(sizeof(NODE));
    PNode pG = (PNode)malloc(sizeof(NODE));
    PNode pH = (PNode)malloc(sizeof(NODE));
    PNode pI = (PNode)malloc(sizeof(NODE));
    PNode pJ = (PNode)malloc(sizeof(NODE));
    PNode pK = (PNode)malloc(sizeof(NODE));
    PNode pL = (PNode)malloc(sizeof(NODE));
    PNode pM = (PNode)malloc(sizeof(NODE));
    PNode pN = (PNode)malloc(sizeof(NODE));
    PNode pO = (PNode)malloc(sizeof(NODE));
    PNode pP = (PNode)malloc(sizeof(NODE));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';
    pG->data = 'G';
    pH->data = 'H';
    pI->data = 'I';
    pJ->data = 'J';
    pK->data = 'K';
    pL->data = 'L';
    pM->data = 'M';
    pN->data = 'N';
    pO->data = 'O';
    pP->data = 'P';

    pA->pLeft = pB;
    pA->pRight = pC;
    pB->pLeft = pD;
    pB->pRight = pE;
    pC->pLeft = pF;
    pC->pRight = pG;
    pD->pLeft = pH;
    pD->pRight = pI;
    pE->pLeft = pJ;
    pE->pRight = pK;
    pF->pLeft = pL;
    pF->pRight = pM;
    pG->pLeft = pN;
    pG->pRight = pO;
    pH->pLeft = pP;
    pH->pRight = NULL;
    pI->pLeft = NULL;
    pI->pRight = NULL;
    pJ->pLeft = NULL;
    pJ->pRight = NULL;
    pK->pLeft = NULL;
    pK->pRight = NULL;
    pL->pLeft = NULL;
    pL->pRight = NULL;
    pM->pLeft = NULL;
    pM->pRight = NULL;
    pN->pLeft = NULL;
    pN->pRight = NULL;
    pO->pLeft = NULL;
    pO->pRight = NULL;
    pP->pLeft = NULL;
    pP->pRight = NULL;

    return pA;//返回值是根节点，所以返回值的类型是PNode
}

int numHeight(PNode node)//计算二叉树的层数，node为根节点
{
    int h = 0;//记录二叉树的层数
    while (node != NULL)//只要根节点不为空，则代表有一层
    {
        h++;
        node = node->pLeft;//将左节点作为下一个循环的根节点
    }
    return h;
}

int numNode(PNode node, int h)//计算完全二叉树的节点数，第二个参数为完全二叉树的层数
{
    if(1 == h)
        return 1;//结束递归的条件——当只剩下一层
    if(numHeight(node->pRight) == h-1)//说明当前二叉树的右子树的最后一层最起码有一个节点，此时左子树为满二叉树
    {
        h--;
        node = node->pRight;//左子树为满二叉树，节点数可以用公式计算，所以用这个函数再计算右子树的节点数，所以将当前根节点的右节点作为新的根节点
        return pow(2,h)-1 + 1 + numNode(node,h);//返回值为满左子树的节点数 + 根节点 + 将右子树的根节点作为根节点进行递归
    }
    else//说明当前二叉树的右子树的最后一层没有节点，则右子树是一个满二叉树（层数要少算一层）
    {
        h--;
        node = node->pLeft;//此时得用这个函数再计算左子树的节点数，所以将当前二叉树的左节点作为根节点
        return pow(2,h-1)-1 + 1 + numNode(node,h);//返回值为满右子树的节点数 + 根节点 + 将左子树的根节点作为根节点进行递归
    }
}
