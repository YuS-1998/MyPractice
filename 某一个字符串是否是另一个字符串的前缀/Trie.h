#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Max 26//小写英文字母的个数

typedef struct _trie{
    bool IsWord;//表示是否是一个结尾
    struct _trie * next[Max];//路径上的单词字母
}Trie,* pTrie;

pTrie Creat_Trie();//创建一棵前缀树
bool trieStartsWith(pTrie , char * );

#endif // TRIE_H_INCLUDED
