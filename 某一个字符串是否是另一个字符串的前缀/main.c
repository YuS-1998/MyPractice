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
            printf("��ǰ�ַ����д���ĳһ�ַ�������һ���ַ�����ǰ׺��\n");
        else
            printf("��ǰ�ַ����в�����ĳһ�ַ�������һ���ַ�����ǰ׺��\n");
    }
    return 0;
}
