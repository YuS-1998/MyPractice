#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <iostream.h>

void swap(int *,int,int);//���������i��jԪ��
void traverse(int *,int);//������ʾ����

void selectSort(int *, int);//ѡ������
void bubbleSort(int *, int);//ð������
void insertSort(int *, int);//��������

void mergeSort(int *, int, int);//�鲢����
void merge(int *, int, int, int);

void quickSort1(int *, int, int);//������1.0
void partition1(int *, int, int, int *);
void quickSort2(int *, int, int);//������2.0
void partition2(int *, int, int, int *, int *);
void quickSort3(int *, int, int);//������3.0
int GetSrand(int *, int);

void heapSort(int *, int);//������
void heapInsert(int *, int);//ĳ�������ڴ���indexλ���ϣ��������ϼ����ƶ�
void heapify(int *, int, int);//ĳ��������indexλ�ã��ܷ������ƶ���ʹ�ѳ�Ϊ����ѣ�

int getDigit(int, int);//ȡ��ĳ�����ĵڼ�λ
void radixSort(int *, int, int);//�������򣨷ǱȽ�����

//�ܽ᣺
//      ʱ�临�Ӷ�   ����ռ临�Ӷ� �ȶ���
//ѡ��O(N2)          O(1)            NO
//ð�ݣ�O(N2)          O(1)            YES
//���룺O(N2)          O(1)            YES
//�鲢��O(NlogN)       O(N)            YES
//���ţ�O(NlogN)       O(logN)         NO
//�ѣ�  O(NlogN)       O(1)            NO
#endif // SORT_H_INCLUDED
