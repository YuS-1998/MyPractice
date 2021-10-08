#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Max 26//СдӢ����ĸ�ĸ���

typedef struct _trie{
    bool IsWord;//��ʾ�Ƿ���һ����β
    struct _trie * next[Max];//·���ϵĵ�����ĸ
}Trie,* pTrie;

pTrie Creat_Trie();//����һ��ǰ׺��
bool trieStartsWith(pTrie , char * );

#endif // TRIE_H_INCLUDED
