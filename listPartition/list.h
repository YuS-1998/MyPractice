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
bool insert_list(PNODE, int, int);//在pHead所指向的链表的第pos个节点的后面插入一个新的节点，该节点的值时val，并且pos的值是从1开始的
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


#endif // LIST_H_INCLUDED
