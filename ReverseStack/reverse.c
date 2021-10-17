#include "stack.h"

int getAndRemoveLast(pStack pS)
{
    //���õݹ飬�������������ջֻʣ���һ��Ԫ���ˣ��������ջ��Ԫ��
    //������ú�������Ȼ����εݹ��г�ջ��Ԫ���ٴ�ѹ��ջ�У��ٽ�ջ��Ԫ��һֱ����ȥ
    //�����������һ������ջ����⣩
    int result;
    popStack(pS,&result);
    if(isEmpty(pS))
        return result;
    else
    {
        int last = getAndRemoveLast(pS);
        pushStack(pS,result);
        return last;
    }
}

void reverseStack(pStack pS)
{
    if(isEmpty(pS))
        return;
    else
    {
        int val = getAndRemoveLast(pS);
        reverseStack(pS);
        pushStack(pS,val);
    }
}
