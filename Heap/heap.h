#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//����һ����ȫ����������Ϊ����Ѻ�С����
//����Ѿ�����������У�����һ���������ĸ��ϵ�Ԫ�ض������ֵ��С����ͬ��
void swap(int *,int,int);//���������еĵ�i���͵�j��Ԫ��
void traverse(int *,int);//������ʾ����
void heapInsert(int *, int);//ĳ�������ڴ���indexλ���ϣ��������ϼ����ƶ�
void heapify(int *, int, int);//ĳ��������indexλ�ã��ܷ������ƶ���ʹ�ѳ�Ϊ����ѣ�

#endif // HEAP_H_INCLUDED
