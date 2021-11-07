#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNum(int *, int, int, int *);//��һ�����������У���ĳ�����Ƿ����
int findLeftNum(int *, int, int);//��һ�����������У��Ҵ��ڵ���ĳ������������λ��
bool localMin(int *, int, int *, int *);//һ���������飨����ȷ����������Ԫ�ز���ͬ���ľֲ���Сֵ���⣬�ҳ�һ������

int main()
{
    int t1,t2;
    int index;
    int num;
    int Arr1[10] = {
        11, 23, 34, 44, 56, 66, 76, 85, 94, 98
    };
    int Arr2[10] = {
        1, 1, 1, 2, 2, 2, 2, 2, 3, 3
    };
    int Arr3[10] = {
        55, 36, 45, 95, 101, 52, 33, 45, 75, 98
    };

    printf("��������Ҫ�ҵ����֣�");

    scanf("%d",&t1);
    if(!findNum(Arr1, 10, t1, &index))
        printf("�Բ�����Ҫ�ҵ�%d���ڸ������С�\n",t1);
    else
        printf("�ҵ��ˣ���Ҫ�ҵ�%d������ĵ�%d��\n",t1,index+1);

    printf("��������Ҫ�ҵ����֣�");
    scanf("%d",&t2);
    index = findLeftNum(Arr2, 10, t2);
    printf("�ҵ��ˣ���Ҫ�ҵ�����ߵ�%d������ĵ�%d��\n",t2,index+1);

    if(!localMin(Arr3,10,&index,&num))
        printf("�Բ��𣡸��������Ҳ����ֲ���Сֵ��\n");
    else
        printf("�ҵ��ˣ��������е�һ���ֲ���СֵΪ��%d��Ԫ��%d\n",index+1,num);
    return 0;
}

bool findNum(int * Arr, int len, int num, int * pIndex)
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;
    while(low <= high)
    {
        if(Arr[mid] == num)
        {
            *pIndex = mid;
            return true;
        }
        else
        {
            if(Arr[mid] < num)//Ҫ�ҵ�����mid���ұ�
            {
               low = mid+1;
               mid = (low+high)/2;
            }
            else//Ҫ�ҵ�����mid�����
            {
                high = mid-1;
                mid = (low+high)/2;
            }
        }
    }
    return false;
}

int findLeftNum(int * Arr, int len, int num)//����һ��������������һ��Ҫ���꣬������ǰ��ֹ����
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;
    int index;
    while(low <= high)
    {
        if(Arr[mid] >= num)
        {
            if(Arr[mid] == num)//����˵����Arr[index]����߻��ҵ���Ҫ�ҵ�num�������index
                index = mid;
            high = mid-1;
            mid = (low+high)/2;
        }
        else//Ҫ�ҵ�����mid���ұ�
        {
           low = mid+1;
           mid = (low+high)/2;
        }
    }
    return index;
}

bool localMin(int * Arr, int len, int * pIndex, int * pNum)
{
    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;

    //�����жϵ�1��Ԫ�ػ������һ��Ԫ���ǲ��Ǿֲ���Сֵ
    if(Arr[0] < Arr[1])
    {
        *pIndex = 0;
        *pNum = Arr[0];
        return true;
    }
    if(Arr[len-1] < Arr[len-2])
    {
        *pIndex = len-1;
        *pNum = Arr[len-1];
        return true;
    }
    while(low <= high)
    {
        if(Arr[mid] < Arr[mid-1] && Arr[mid] < Arr[mid+1])
        {
            *pIndex = mid;
            *pNum = Arr[mid];
            return true;
        }
        else
            if(Arr[mid] > Arr[mid-1])
            {
                high = mid-1;
                mid = (low+high)/2;
            }
            else
            {
                low = mid+1;
                mid = (low+high)/2;
            }
    }
    return false;
}
