#include <stdio.h>
#include <stdlib.h>

int MaxLen(int *, int , int );
int compare(int , int );
//int Summary(int *,int *);

int main()
{
    //int Arr[5] = {1, 2, 1, 1, 1};
    int Arr[9] = {2, 3, 1, 1, 1, 1, 1, 3, 2};
    int len = MaxLen(Arr, 9, 5);
    printf("�ۼӺ�Ϊ5���������ĳ���Ϊ��%d\n",len);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

//int Summary(int *pL, int *pR)//��������ָ���м��������������ۼӺ�
//{
//    int * p1 = pL;
//    int * p2 = pR;//����������ʱ�ı���
//    int sum = 0;
//
//    while(p1 != p2)
//    {
//        sum += *p1;
//        p1++;
//    }
//    sum += *p2;
//    return sum;
//}

int MaxLen(int * Arr, int len, int k)
{
    int i;//ѭ������
    int *pL = &Arr[0];//������ָ�룬ָ�������׵�ַ
    int *pR = &Arr[0];//������ָ�룬��ʼ��Ϊ�����׵�ַ
    int maxLen = 0;//����������鳤��
    int sum = Arr[0];//��¼��ǰ������ĺ�

    for(i = 0; ; i++)
    {
        //��������ָ���Ƶ����һ��Ԫ�أ�ͬʱ��ǰ��������ۼӺ�С�ڵ���k�����ۼӺ�С�ڵ���kʱ����ʱ��ָ���Ѿ�û�������ˣ��ۼӺ�û�����ӣ���ָ���������ƣ��ۼӺ��ֻ��С��û�����壩��
        //�����������ָ�붼ָ��ĩԪ��ʱ����ѭ��
        //sum = Summary(pL, pR);
        printf("��%d��ѭ�����ۼӺ�Ϊ%d\n",i+1,sum);
        if((sum <= k && pR == &Arr[len-1]) || (pL == &Arr[len-1] && pR == &Arr[len-1]))
        {
            maxLen = compare(maxLen, pR-pL+1);
            return maxLen;
        }
        else
        {
            if(sum == k)
                maxLen = compare(maxLen, pR-pL+1);//�������������ۼӺ͵���kʱ��������������鳤��
            if(sum <= k)
            {
                pR++;
                sum += *pR;//���ۼӺ��м����¼ӵ�����
            }

            else
            {
                sum -= *pL;//���ۼӺ���ȥ����ָ���ʱָ���Ԫ��
                pL++;
            }

        }
    }
}
