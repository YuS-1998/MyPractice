#ifndef MAXSIZE_H_INCLUDED
#define MAXSIZE_H_INCLUDED
#include <stdbool.h>

typedef struct _node{
    int data;//������
    struct _node * pNext;//ָ����
}NODE,* pNODE;//����һ���ṹ�����ڵ�

typedef struct _stack{
    pNODE pBottom;//ջ��ָ��
    pNODE pTop;//ջ��ָ��
}STACK,* pSTACK;//����һ���ṹ����ջ

void initStack(pSTACK);//��ʼ��ջ
bool emptyStack(pSTACK);//�ж�ջ�Ƿ�Ϊ��
void pushStack(pSTACK , int);//ѹջ
bool popStack(pSTACK , int *);//��ջ

int compare(int , int );
int maxSizeA(int *, int );//��ֱ��ͼ�������ε��������һ������Ϊ��������飬�ڶ�������Ϊ���鳤��
int maxSizeM(int *, int , int );//�������m*n�ľ����з���������1�ĸ�����һ���еĸ���Ԫ�ر�ʾ��ǰλ�������ж��ٸ�������1����Ȼ����������ĺ������м���

#endif // MAXSIZE_H_INCLUDED
