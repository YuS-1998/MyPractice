#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//堆是一种完全二叉树，分为大根堆和小根堆
//大根堆就是在这个堆中，任意一个子树它的根上的元素都是最大值；小根堆同理
void swap(int *,int,int);//交换数组中的第i个和第j个元素
void traverse(int *,int);//遍历显示数组
void heapInsert(int *, int);//某个数现在处在index位置上，让它往上继续移动
void heapify(int *, int, int);//某个数处在index位置，能否往下移动（使堆成为大根堆）

#endif // HEAP_H_INCLUDED
