#include <stdio.h>
#include <stdlib.h>

int compare(int , int );
int maxSize(int *, int ,int );

int main()
{
    int Matrix[3][3] = {{1,3,5},{-3,5,-2},{9,1,-3}};
    int Res = maxSize(Matrix, 3, 5);
    printf("���������ۼӺ�С�ڵ���9������Ӿ���Ĵ�СΪ%d\n",Res);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSize(int * Matrix, int n, int k)
{
    int i,j,p,q;//ѭ������
    int Max = 0;//����Ӿ����С
    int Arr[n];//��һ�������¼�����ۼӵĺ�
    int h[n];//��һ���������ȼ�¼����������ĵ�j��Ԫ��ʱ���ۼӺ�
    int (*pMatrix)[n] = Matrix;


    //����һ���˼ά��ͬ��ͬ�����ǵ�1�У���1��2�У���1��2��3�С�����2�У���2��3�У������Դ�����
    //�ڽ��ۼӺ���С�����鿼��ʱ�����Բο��ڶ����е��ۼӺ�С�ڵ���k����������鳤�ȵķ���
    //�˴��ṩһ���µķ�����
    //��һ���������ȼ�¼����������ĵ�j��Ԫ��ʱ���ۼӺͣ��õ�һ������Ϊn������h
    //�ڶ�����������ԭ����ĵ�j��Ԫ��ʱ���ҵ�h�����е�j��Ԫ��֮ǰ��һ�����ڵ���h[j]-k�������������Ԫ��֮��ľ���
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Arr[j] = 0;//��Arr��ʼ��Ϊȫ������
        }

        for(j = i; j < n; j++)
        {
            for(p = 0; p < n; p++)
            {
                Arr[p] += *(*(pMatrix+j)+p);//�ۼ��ϵ�j�е�Ԫ��
                printf("%d ",Arr[p]);
            }
            printf("\n");

            h[0] = Arr[0];//h�������Ԫ�س�ʼ��ΪArr�������Ԫ��
            for(p = 1; p < n; p++)
            {
                h[p] = h[p-1] + Arr[p];//�ۼӵõ�����h
                printf("%d ",h[p]);
            }
            printf("\n");

            for(p = 0; p < n; p++)
            {
                int temp = 0;
                for(q = 0; q <= p; q++)
                {
                    if(h[q] >= h[p] - k)
                    {
                        if(p == q && h[q] >= k)
                            temp = 0;
                        else
                        {
                            temp = p - q + 1;//�ҵ���һ���ۼӺʹ��ڵ���h[p]-k��Ԫ�ر�ǩ��������Ԫ��֮��ľ���
                            break;
                        }
                    }
                }
                printf("%d ",temp);
                Max = compare(Max, temp*(j-i+1));
                printf("%d\n",Max);
            }
        }
    }
    return Max;
}
