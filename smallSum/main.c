#include <stdio.h>
#include <stdlib.h>

int process(int *,int, int);
int merge(int *,int, int, int);

int main()
{
    //С�͵���˼��������ĳ��Ԫ��������б���С��Ԫ�صĺ�
    //�����С�;������е�С�͵ĺ�
    int Arr[5] = {1, 3, 4, 2, 5};
    int smallSum = process(Arr,0,4);
    printf("�������С�͵���%d\n",smallSum);
    return 0;
}

//������ʵ��ʱ����˼��������ĳ��Ԫ���ұ����б������Ԫ�صĺ�
int process(int * Arr,int L, int R)
{
    if(L == R)
        return 0;
    int mid = L+(R-L)/2;
    return process(Arr,L,mid) + process(Arr,mid+1,R) + merge(Arr,L,mid,R);//����ֵ�����������С�ͼ��Ұ�������С�ͼӰ����Ǻϲ�ʱ���С��
}

int merge(int * Arr,int L, int M, int R)
{
    int Help[R-L+1];
    int i = 0;
    int j;
    int p1 = L;
    int p2 = M+1;
    int res = 0;
    while(p1 <= M && p2 <= R)
    {
        if(Arr[p1] < Arr[p2])
        {
            res += (R-p2+1)*Arr[p1];//һ��Ҫ������Ϊ�����Ϳ�����R��ȥ��ǰ��ָ��p2����Ϊ�ź����ˣ��ұߵ�Ԫ��һ����Arr[p2]��Ҳ�ͱ�Arr[p1]��������С��
            Help[i] = Arr[p1];
            p1++;
            i++;
        }
        else
        {
            Help[i] = Arr[p2];//����ע����鲢�����һ���ܴ�Ĳ�𣺵�Arr[p1]=Arr[p2]ʱ�����ŵ�Help�����е����ұߵ�����Arr[p2]��
            //��ΪArr[p1]��û�м������Ұ�����������б������Ԫ�أ������ƶ�ָ��
            p2++;
            i++;
        }
    }
    while(p1 <= M)
    {
        Help[i] = Arr[p1];
        p1++;
        i++;
    }
    while(p2 <= R)
    {
        Help[i] = Arr[p2];
        p2++;
        i++;
    }
    for(j = 0; j < i; j++)
        Arr[L+j] = Help[j];
    return res;
}
