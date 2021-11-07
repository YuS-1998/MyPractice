#include <stdio.h>
#include <stdlib.h>

void swap(int *,int,int);//���������еĵ�i���͵�j��Ԫ��
void traverse(int *,int);//������ʾ����
void DutchFlag1(int *, int, int);//����������һ�������һ������Ҫ��ȸ���С�ڵ��ڵ�Ԫ�ض����������ߣ���Ķ����Ұ��
void DutchFlag2(int *, int, int);//���ף�������Ļ����ϣ������ڸ�������Ԫ�ط��м�

int main()
{
    int Arr1[10] = {
        1, 6, 7, 4, 9, 3, 2, 8, 5, 0
    };
    int Arr2[10] = {
        1, 6, 7, 4, 5, 3, 2, 8, 9, 5
    };
    printf("****************������****************\n");
    printf("����ǰ��");
    traverse(Arr1,10);
    printf("\n");
    DutchFlag1(Arr1,10,5);
    printf("�����");
    traverse(Arr1,10);
    printf("\n");

    printf("****************���װ�****************\n");
    printf("����ǰ��");
    traverse(Arr2,10);
    printf("\n");
    DutchFlag2(Arr2,10,5);
    printf("�����");
    traverse(Arr2,10);
    return 0;
}

void swap(int * Arr,int i,int j)
{
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
    return;
}

void traverse(int * Arr,int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%d ",Arr[i]);
    return;
}

void DutchFlag1(int * Arr, int len, int num)
{
    int i = 0;
    int flag = -1;//��ΪС�ڵ������ı߽�

    while(i <= len)
    {
        if(Arr[i] <= num)
        {
            swap(Arr,i,flag+1);//�����ǰ��С�ڵ��ڸ�����num���ѵ�ǰ����С�ڵ������ı߽����һ��������
            flag++;//�ٽ�С�ڵ�����������չһλ
            i++;
        }
        else
            i++;//�����ǰ�����ڸ�����num�������������һ��Ԫ��
//        traverse(Arr,10);
//        printf("\n");
    }
    return;
}

void DutchFlag2(int * Arr, int len, int num)
{
    int i = 0;
    int flagL = -1;//��ΪС�������ұ߽�
    int flagR = len;//��Ϊ����������߽�

    while(i < flagR)
    {
        if(Arr[i] < num)
        {
            swap(Arr,i,flagL+1);//�����ǰ��С�ڸ�����num���ѵ�ǰ����С�ڵ������ı߽����һ��������
            flagL++;//�ٽ�С����������չһλ
            i++;
        }
        else
        {
            if(Arr[i] == num)
                i++;//�����ǰ�����ڸ�����num�������������һ��Ԫ��
            else
            {
                swap(Arr,i,flagR-1);//�����ǰ�����ڸ�����num���ѵ�ǰ���ʹ��ڵ������ı߽��ǰһ��������
                flagR--;//ע�������������������ǰ��չһλ�������ƶ�i����Ϊ��������������û�б���������ƶ���i�ͻ��������
            }
        }
//        traverse(Arr,10);
//        printf("\n");
    }
    return;
}
