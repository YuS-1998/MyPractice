#ifndef MAXSIZE_H_INCLUDED
#define MAXSIZE_H_INCLUDED
#include <stdbool.h>

typedef struct _node{
    int data;//数据域
    struct _node * pNext;//指针域
}NODE,* pNODE;//定义一个结构体作节点

typedef struct _stack{
    pNODE pBottom;//栈底指针
    pNODE pTop;//栈顶指针
}STACK,* pSTACK;//定义一个结构体作栈

void initStack(pSTACK);//初始化栈
bool emptyStack(pSTACK);//判断栈是否为空
void pushStack(pSTACK , int);//压栈
bool popStack(pSTACK , int *);//出栈

int compare(int , int );
int maxSizeA(int *, int );//求直方图中最大矩形的面积，第一个参数为输入的数组，第二个参数为数组长度
int maxSizeM(int *, int , int );//先求矩阵m*n的矩阵列方向上连续1的个数（一行中的各个元素表示当前位置向上有多少个连续的1），然后利用上面的函数进行计算

#endif // MAXSIZE_H_INCLUDED
