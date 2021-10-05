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

    return pA;//����ֵ�Ǹ��ڵ㣬���Է���ֵ��������PNode
}

int numHeight(PNode node)//����������Ĳ�����nodeΪ���ڵ�
{
    int h = 0;//��¼�������Ĳ���
    while (node != NULL)//ֻҪ���ڵ㲻Ϊ�գ��������һ��
    {
        h++;
        node = node->pLeft;//����ڵ���Ϊ��һ��ѭ���ĸ��ڵ�
    }
    return h;
}

int numNode(PNode node, int h)//������ȫ�������Ľڵ������ڶ�������Ϊ��ȫ�������Ĳ���
{
    if(1 == h)
        return 1;//�����ݹ������������ֻʣ��һ��
    if(numHeight(node->pRight) == h-1)//˵����ǰ�������������������һ����������һ���ڵ㣬��ʱ������Ϊ��������
    {
        h--;
        node = node->pRight;//������Ϊ�����������ڵ��������ù�ʽ���㣬��������������ټ����������Ľڵ��������Խ���ǰ���ڵ���ҽڵ���Ϊ�µĸ��ڵ�
        return pow(2,h)-1 + 1 + numNode(node,h);//����ֵΪ���������Ľڵ��� + ���ڵ� + ���������ĸ��ڵ���Ϊ���ڵ���еݹ�
    }
    else//˵����ǰ�������������������һ��û�нڵ㣬����������һ����������������Ҫ����һ�㣩
    {
        h--;
        node = node->pLeft;//��ʱ������������ټ����������Ľڵ��������Խ���ǰ����������ڵ���Ϊ���ڵ�
        return pow(2,h-1)-1 + 1 + numNode(node,h);//����ֵΪ���������Ľڵ��� + ���ڵ� + ���������ĸ��ڵ���Ϊ���ڵ���еݹ�
    }
}
