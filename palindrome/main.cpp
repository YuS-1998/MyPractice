#include <iostream>
#include <stack>
#include "list.h"

using namespace std;

//给定一个链表的头结点head，请判断该链表是否为回文结构（正念反念都一样，eg.7 8 9 8 7）
bool isPalindrome1(Node *head){
    //法一：用一个栈，将链表中的元素都压入栈，然后依次出栈与链表正向对比，如果都一样就是回文结构
    stack<int> stack;
    Node *cur = head;
    while(cur != NULL){
        stack.push(cur->value);
        cur = cur->next;
    }
    while(head != NULL){
        if(head->value != stack.top())
            return false;
        stack.pop();
        head = head->next;
    }
    return true;
}

bool isPalindrome2(Node *head){
    //法二：利用快慢指针让right指针走到中间节点的后一个，然后将后面一半链表的值压入栈内，通过出栈和链表前面一半正向对比。这样能节省一半的空间复杂度
    if(head == NULL || head->next == NULL)
        return true;
    PNODE right = head->next;//慢指针，最后指向后面一半的第一个节点
    PNODE cur = head;//快指针
    while(cur->next != NULL && cur->next->next != NULL){
        right = right->next;
        cur = cur->next->next;//快慢指针，快指针走两步，慢指针走一步，快指针走到头，慢指针走到链表的中间
    }
    stack<int> stack;
    while(right != NULL){
        stack.push(right->value);
        right = right->next;
    }
    while(!stack.empty()){
        if(head->value != stack.top())
            return false;
        stack.pop();
        head = head->next;
    }
    return true;
}

//需要O(1)的额外空间
bool isPalindrome3(Node *head){
    //法三：首先利用快慢指针找到链表中点，然后将链表的右半部分反向，接着从两端向中间比较是否是回文结构，最后再将右半边反向回去
    if(head == NULL || head->next == NULL)
        return true;
    PNODE n1 = head;
    PNODE n2 = head;
    while(n2->next != NULL && n2->next->next != NULL)
    {//这里利用快慢指针找到中间节点，注意与法二的区别在于慢指针设置的初始位置不同
        n1 = n1->next;//慢指针
        n2 = n2->next->next;//快指针
    }
    n2 = n1->next;//让n2指向中间节点的下一个节点
    n1->next = NULL;//断开中间节点和后面的连接
    PNODE n3 = NULL;//临时节点
    while(n2 != NULL)
    {//让中间节点后面的链表反向
        n3 = n2->next;//保存n2后面的链表
        n2->next = n1;//n2反过来指向n1
        n1 = n2;//n1移动
        n2 = n3;//n2移动
    }
    n3 = n1;//此时n1指向原链表的最后一个节点，用n3保存最后一个节点
    n2 = head;//n2指向左边第一个节点
    bool res = true;
    while(n1 != NULL && n2 != NULL)
    {//两端同时向中间移动并且比较
        if(n1->value != n2->value)
        {
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    //把右边再反转回去
    n1 = n3->next;
    n3->next = NULL;
    while(n1 != NULL)
    {
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
}

int main()
{
    PNODE pHead = NULL;//等价于struct Node * pHead = NULL;
    pHead = create_list();//create_list功能：创建一个非循环单链表，并将该链表的头节点的地址赋给pHead
    traverse_list(pHead);//遍历链表
    //if(isPalindrome1(pHead->next))
    //if(isPalindrome2(pHead->next))
    if(isPalindrome3(pHead->next))
        cout << "该链表是一个回文结构" << endl;
    else
        cout << "该链表不是回文结构" << endl;
    return 0;
}
