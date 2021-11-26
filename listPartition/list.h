#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <malloc.h>

typedef struct Node{
    int value;
    struct Node *next;
//    Node(int data){
//        this.value = data;
//    }

}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);//��pHead��ָ�������ĵ�pos���ڵ�ĺ������һ���µĽڵ㣬�ýڵ��ֵʱval������pos��ֵ�Ǵ�1��ʼ��
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


#endif // LIST_H_INCLUDED
