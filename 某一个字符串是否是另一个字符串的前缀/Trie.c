#include "Trie.h"

pTrie Creat_Trie()
{
	pTrie root =(pTrie)malloc(sizeof(Trie));
	memset(root,0,sizeof(Trie));
	return root;
}

bool trieStartsWith(pTrie trie, char * SetString)
{
    //有两种情况说明某一个字符串是另一个字符串的前缀
    //1、当前字符串遍历到结束仍然是在前缀树中，没有产生新的分支，说明当前字符串是这个分支的前缀
    //2、当前字符串一直在前缀树中，且遍历到某一个分支的结尾，说明这个分支是当前字符串的前缀
    int t = 0;//作为当前字符串遍历时是否有创建新的分支的标志
    while(*SetString)
    {
        if(trie->IsWord && t == 0)
            return true;//判断一下如果在遍历当前字符串时，已经遍历到前缀树的某个结尾了，且在此期间没有产生别的分支（情况2），则返回true
        if(!trie->next[*SetString-'a'])
        {
            trie->next[*SetString-'a'] = Creat_Trie();//如果没有这个字母的分支，则创建一个
            t++;
        }
        trie = trie->next[*SetString-'a'];//并且移到下一个节点
        SetString++;
    }
    trie->IsWord = true;
    if(t == 0)//此时当前字符串已经遍历完了，判断一下过程中是否产生了新的分支（情况1）
        return true;
    else
        return false;
}
