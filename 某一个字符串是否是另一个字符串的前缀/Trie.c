#include "Trie.h"

pTrie Creat_Trie()
{
	pTrie root =(pTrie)malloc(sizeof(Trie));
	memset(root,0,sizeof(Trie));
	return root;
}

bool trieStartsWith(pTrie trie, char * SetString)
{
    //���������˵��ĳһ���ַ�������һ���ַ�����ǰ׺
    //1����ǰ�ַ���������������Ȼ����ǰ׺���У�û�в����µķ�֧��˵����ǰ�ַ����������֧��ǰ׺
    //2����ǰ�ַ���һֱ��ǰ׺���У��ұ�����ĳһ����֧�Ľ�β��˵�������֧�ǵ�ǰ�ַ�����ǰ׺
    int t = 0;//��Ϊ��ǰ�ַ�������ʱ�Ƿ��д����µķ�֧�ı�־
    while(*SetString)
    {
        if(trie->IsWord && t == 0)
            return true;//�ж�һ������ڱ�����ǰ�ַ���ʱ���Ѿ�������ǰ׺����ĳ����β�ˣ����ڴ��ڼ�û�в�����ķ�֧�����2�����򷵻�true
        if(!trie->next[*SetString-'a'])
        {
            trie->next[*SetString-'a'] = Creat_Trie();//���û�������ĸ�ķ�֧���򴴽�һ��
            t++;
        }
        trie = trie->next[*SetString-'a'];//�����Ƶ���һ���ڵ�
        SetString++;
    }
    trie->IsWord = true;
    if(t == 0)//��ʱ��ǰ�ַ����Ѿ��������ˣ��ж�һ�¹������Ƿ�������µķ�֧�����1��
        return true;
    else
        return false;
}
