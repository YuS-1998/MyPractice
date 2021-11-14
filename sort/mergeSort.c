#include "Sort.h"

//�ݹ�ĸ��Ӷ�Ҫ��master��ʽ������a=2,b=2,d=1�����Թ鲢�����ʱ�临�Ӷ�ΪO(NlogN)
void mergeSort(int * Arr, int L,int R)//ʹ�õݹ飬ÿ��ȡһ�룬��merge������������һ�룬��������ұ�һ�룬�ٺ�����һ������
{
    if(L == R)
        return;
    int mid = L+(R-L)/2;//���������Ա�����ջ��Ҳ��д��L+(R-L)>>1����������һλ��Ҳ���ǳ���2
    mergeSort(Arr,L,mid);
    mergeSort(Arr,mid+1,R);
    merge(Arr,L,mid,R);
}

void merge(int * Arr, int L, int M, int R)//���ʱ��������ߺ��Ұ�߶��ź����ˣ��������������ָ���һ���������飬�������������鰴��С�����˳���ٺϲ�����
{
    int Help[R-L+1];
    int i = 0;
    int j;
    int p1 = L;
    int p2 = M+1;
    while(p1 <= M && p2 <= R)//p1��p2��û�г�����Χ��˭С����˭
    {
        if(Arr[p1] <= Arr[p2])
        {
            Help[i] = Arr[p1];
            p1++;
            i++;
        }
        else
        {
            Help[i] = Arr[p2];
            p2++;
            i++;
        }
    }
    while(p1 <= M)//����һ�������˷�Χ���Ͱ���һ������
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
//    traverse(Help,i);
//    printf("\n");
    for(j = 0; j < i; j++)
        Arr[L+j] = Help[j];
    return;
}
