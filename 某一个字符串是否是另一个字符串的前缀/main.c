#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

int main()
{
    int i;
    char * Strings[5] = {
        "abcde","abe","abcdef","abc","oped"
    };

    pTrie root = Creat_Trie();
    for(i = 0; i < 5; i++)
    {
        if(trieStartsWith(root, Strings[i]))
            printf("当前字符串中存在某一字符串是另一个字符串的前缀！\n");
        else
            printf("当前字符串中不存在某一字符串是另一个字符串的前缀！\n");
    }
    return 0;
}
