#ifndef BTNODE_H_INCLUDED
#define BTNODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node{
    int data;//������
    struct _node * pLeft;//��ڵ�
    struct _node * pRight;//�ҽڵ�
}NODE,* PNode;

PNode CreateBTree();//����һ��������
int numNode(PNode , int );//������ȫ�������Ľڵ���
int numHeight(PNode );//����������Ĳ���

#endif // BTNODE_H_INCLUDED
