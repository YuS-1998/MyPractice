#include "stack.h"

int getAndRemoveLast(pStack pS)
{
    //利用递归，结束条件：如果栈只剩最后一个元素了，返回这个栈底元素
    //否则调用函数本身，然后将这次递归中出栈的元素再次压回栈中，再将栈底元素一直传上去
    //（可以想成用一个辅助栈来理解）
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
