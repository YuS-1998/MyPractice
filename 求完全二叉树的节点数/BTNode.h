#ifndef BTNODE_H_INCLUDED
#define BTNODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node{
    int data;//数据域
    struct _node * pLeft;//左节点
    struct _node * pRight;//右节点
}NODE,* PNode;

PNode CreateBTree();//建立一个二叉树
int numNode(PNode , int );//计算完全二叉树的节点数
int numHeight(PNode );//计算二叉树的层数

#endif // BTNODE_H_INCLUDED
