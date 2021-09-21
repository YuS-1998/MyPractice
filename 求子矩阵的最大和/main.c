#include <stdio.h>
#include <stdlib.h>

int maxSum(int *, int );
int compare(int , int );

int main()
{
    int Matrix[3][3] = {{1,3,5},{-3,5,-2},{9,1,-3}};
    int Res = maxSum(Matrix, 3);
    printf("���������Ӿ��������Ϊ%d\n",Res);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSum(int * Matrix, int n)//Matrix��һ��n*n�ľ���
{
    //������һ��5*5�ľ����㷨����Ϊ��
    //�������μ����1�У���1��2�У���1��2��3�С�����2�У���2��3�С�����4��5�У���5���Ӿ����н�Ԫ����ӵõ�����
    //����������������ۼӺ͵ķ�������������ۼӺ͡�
    //���õ��Ľ������Ҫ����Ӿ��������

    int i, j, k;//ѭ������
    int Res = 0;//������¼�������
    int cur;//������¼������������ۼӺ�ʱ��Ŀǰ���ۼӺ�
    int resTemp;//��ʱ������������¼ÿ���������������ۼӺ͵Ľ��
    int Arr[n];//������¼�Ӿ����н�Ԫ����ӵõ�������
    int (*pMatrix)[n] = Matrix;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Arr[j] = 0;//ÿ��ѭ���Ƚ�Arr[n]��ʼ��Ϊȫ������
        }

        for(j = i; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                Arr[k] += *(*(pMatrix+j)+k);//ÿ�ζ��ۼ���һ�У��õ���ǰ�Ӿ�������ӵõ�������
            }

            cur =  resTemp = Arr[0];//��cur��resTemp����ʼ��ΪArr�ĵ�һ��Ԫ��
            for(k = 1; k < n; k++)
            {
                cur += Arr[k];
                resTemp = compare(cur, resTemp);//�Ƚϸ�������ۼӺ�
                cur = compare(0, cur);//����ʱ�ۼӺ�С��0�����ۼӺ�����
            }
            Res = compare(resTemp, Res);//�Ƚϸ����Ӿ�������
        }
    }
    return Res;
}
