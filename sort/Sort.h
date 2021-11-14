#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <iostream.h>

void swap(int *,int,int);//交换数组的i和j元素
void traverse(int *,int);//遍历显示数组

void selectSort(int *, int);//选择排序
void bubbleSort(int *, int);//冒泡排序
void insertSort(int *, int);//插入排序

void mergeSort(int *, int, int);//归并排序
void merge(int *, int, int, int);

void quickSort1(int *, int, int);//快排序1.0
void partition1(int *, int, int, int *);
void quickSort2(int *, int, int);//快排序2.0
void partition2(int *, int, int, int *, int *);
void quickSort3(int *, int, int);//快排序3.0
int GetSrand(int *, int);

void heapSort(int *, int);//堆排序
void heapInsert(int *, int);//某个数现在处在index位置上，让它往上继续移动
void heapify(int *, int, int);//某个数处在index位置，能否往下移动（使堆成为大根堆）

int getDigit(int, int);//取出某个数的第几位
void radixSort(int *, int, int);//基数排序（非比较排序）

//总结：
//      时间复杂度   额外空间复杂度 稳定性
//选择：O(N2)          O(1)            NO
//冒泡：O(N2)          O(1)            YES
//插入：O(N2)          O(1)            YES
//归并：O(NlogN)       O(N)            YES
//快排：O(NlogN)       O(logN)         NO
//堆：  O(NlogN)       O(1)            NO
#endif // SORT_H_INCLUDED
