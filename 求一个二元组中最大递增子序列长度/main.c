#include <stdio.h>
#include <stdlib.h>

void sortArr(int *,int );//������
int lenArr(int *, int);//����������������ٸ���Ԫ��

int main()
{
    int i;
    int Arr[8][2] = {
        {5,4}, {6,4}, {6,7}, {2,3}, {2,4}, {3,6}, {4,7}, {5,8}
    };
    int sizeArr = 8;
    printf("***************����ǰ***************\n");
    for(i = 0;i < sizeArr; i++)
    {
        printf("{%d,%d}\n",Arr[i][0],Arr[i][1]);
    }
    //int * p =
    sortArr(Arr, sizeArr);
    printf("***************�����***************\n");
    for(i = 0;i < sizeArr; i++)
    {
        printf("{%d,%d}\n",Arr[i][0],Arr[i][1]);
    }
    int len = lenArr(Arr,sizeArr);
    printf("�ö�Ԫ��������������%d����\n",len);
    return 0;
}

void sortArr(int * Arr, int sizeArr)//Arr��һ��N*2�����飬sizeArr�����ж�Ԫ����ĸ���
{
    //�����򣺰�a���򣬣�a��ͬʱ��b����Ĺ���
    //Arr[i][0]��ʾ��i����Ԫ�����a��Arr[i][1]��ʾ��i����Ԫ�����b
    int i,j;//ѭ������
    int t[2];//��ʱ������������ʱ��Ŷ�Ԫ����
    int (*pArr)[2] = Arr;
    //ð������
    for(i = 0; i < sizeArr-1; i++)//��Ȧ���ƱȽ�����
    {
        for(j = 0; j < sizeArr-i-1; j++)//��Ȧ����ÿ�ֱȽϴ���
        {
            if(*(*(pArr+j)+0) > *(*(pArr+j+1)+0))
            //if(*(*(Arr+j)+0) > *(*(Arr+j+1)+0))
            {
                t[0] = *(*(pArr+j)+0);
                t[1] = *(*(pArr+j)+1);
                *(*(pArr+j)+0) = *(*(pArr+j+1)+0);
                *(*(pArr+j)+1) = *(*(pArr+j+1)+1);
                *(*(pArr+j+1)+0) = t[0];
                *(*(pArr+j+1)+1) = t[1];
            }
            else
                if(*(*(pArr+j)+0) == *(*(pArr+j+1)+0))//���������Ԫ��a��ͬ
                {
                    if(*(*(pArr+j)+1) < *(*(pArr+j+1)+1))//�Ƚ�b��bҪ��������
                    {
                        t[0] = *(*(pArr+j)+0);
                        t[1] = *(*(pArr+j)+1);
                        *(*(pArr+j)+0) = *(*(pArr+j+1)+0);
                        *(*(pArr+j)+1) = *(*(pArr+j+1)+1);
                        *(*(pArr+j+1)+0) = t[0];
                        *(*(pArr+j+1)+1) = t[1];
                    }
                }
        }
    }
    //return *pArr;
}

int lenArr(int * Arr, int sizeArr)
{
    //����һ�������еĽⷨ2����
    int i,j;
    int (*pArr)[2] = Arr;
    int h[sizeArr];//���h������������Ŷ�Ԫ���е�bԪ�صģ�����������һ�������еĽⷨ2��ͬ
    h[0] = *(*(pArr+0)+1);
    int len = 1;

    for(i = 1; i < sizeArr; i++)
    {
        int temp = 0;
        for(j = 0; j < len; j++)
        {
            if(*(*(pArr+i)+1) <= h[j])
            {
                h[j] = *(*(pArr+i)+1);
                temp++;
                break;
            }
        }
        if(0 == temp)
        {
            h[len] = *(*(pArr+i)+1);
            len++;
        }
    }
    return len;
}
