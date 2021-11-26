#include <iostream>
#include <stack>
#include "list.h"

using namespace std;

//����һ�������ͷ���head�����жϸ������Ƿ�Ϊ���Ľṹ������һ����eg.7 8 9 8 7��
bool isPalindrome1(Node *head){
    //��һ����һ��ջ���������е�Ԫ�ض�ѹ��ջ��Ȼ�����γ�ջ����������Աȣ������һ�����ǻ��Ľṹ
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
    //���������ÿ���ָ����rightָ���ߵ��м�ڵ�ĺ�һ����Ȼ�󽫺���һ�������ֵѹ��ջ�ڣ�ͨ����ջ������ǰ��һ������Աȡ������ܽ�ʡһ��Ŀռ临�Ӷ�
    if(head == NULL || head->next == NULL)
        return true;
    PNODE right = head->next;//��ָ�룬���ָ�����һ��ĵ�һ���ڵ�
    PNODE cur = head;//��ָ��
    while(cur->next != NULL && cur->next->next != NULL){
        right = right->next;
        cur = cur->next->next;//����ָ�룬��ָ������������ָ����һ������ָ���ߵ�ͷ����ָ���ߵ�������м�
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

//��ҪO(1)�Ķ���ռ�
bool isPalindrome3(Node *head){
    //�������������ÿ���ָ���ҵ������е㣬Ȼ��������Ұ벿�ַ��򣬽��Ŵ��������м�Ƚ��Ƿ��ǻ��Ľṹ������ٽ��Ұ�߷����ȥ
    if(head == NULL || head->next == NULL)
        return true;
    PNODE n1 = head;
    PNODE n2 = head;
    while(n2->next != NULL && n2->next->next != NULL)
    {//�������ÿ���ָ���ҵ��м�ڵ㣬ע���뷨��������������ָ�����õĳ�ʼλ�ò�ͬ
        n1 = n1->next;//��ָ��
        n2 = n2->next->next;//��ָ��
    }
    n2 = n1->next;//��n2ָ���м�ڵ����һ���ڵ�
    n1->next = NULL;//�Ͽ��м�ڵ�ͺ��������
    PNODE n3 = NULL;//��ʱ�ڵ�
    while(n2 != NULL)
    {//���м�ڵ�����������
        n3 = n2->next;//����n2���������
        n2->next = n1;//n2������ָ��n1
        n1 = n2;//n1�ƶ�
        n2 = n3;//n2�ƶ�
    }
    n3 = n1;//��ʱn1ָ��ԭ��������һ���ڵ㣬��n3�������һ���ڵ�
    n2 = head;//n2ָ����ߵ�һ���ڵ�
    bool res = true;
    while(n1 != NULL && n2 != NULL)
    {//����ͬʱ���м��ƶ����ұȽ�
        if(n1->value != n2->value)
        {
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    //���ұ��ٷ�ת��ȥ
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
    PNODE pHead = NULL;//�ȼ���struct Node * pHead = NULL;
    pHead = create_list();//create_list���ܣ�����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����pHead
    traverse_list(pHead);//��������
    //if(isPalindrome1(pHead->next))
    //if(isPalindrome2(pHead->next))
    if(isPalindrome3(pHead->next))
        cout << "��������һ�����Ľṹ" << endl;
    else
        cout << "�������ǻ��Ľṹ" << endl;
    return 0;
}
