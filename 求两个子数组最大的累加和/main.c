#include <stdio.h>
#include <stdlib.h>

int maxSum(int *, int);

int main()
{
    int Arr[8] = {3, -2, 1, -6, 4, 3, -2, 3};
    int Max = maxSum(Arr, 8);
    printf("���������������ۼӺ͵ĺ�Ϊ��%d\n",Max);
    return 0;
}

int compare(int a, int b)//����ϴ��һ��
{
    if(a >= b)
        return a;
    else
        return b;
}

int maxSum(int * Arr, int len)
{
    int i;//ѭ������
    int Lcur = Arr[0];//��Lcur��¼��������ĵ�ǰ�ۼӺͣ���ʼ��Ϊԭ�������Ԫ��
    int Lres = Arr[0];//��һ��������¼0-iԪ�ص������������ۼӺͣ���ʼ��Ϊԭ�������Ԫ��
    int R[len];//��һ�������¼i+1-NԪ�ص������������ۼӺͣ����ҵ��������
    R[len-1] = Arr[len-1];//R�����ĩԪ�س�ʼ��Ϊԭ�����ĩԪ��
    int Rcur = R[len-1];//Rcur��¼��ǰ���ۼӺͣ���ʼ��ΪR�����ĩԪ��
    int Rres = R[len-1];//Rres��¼����ۼӺͣ���ʼ��ΪR�����ĩԪ��
    int res;//��res������¼���������������ۼӺ�

    if(NULL == Arr || len < 2)
        return 0;

    //�ȴ��������������������R
    for(i = len-2; i >= 0; i--)
    {
        Rcur = compare(0, Rcur);//��curС��0����cur����
        Rcur += Arr[i];//���㵱ǰ�ۼӺ�
        Rres = compare(Rcur, Rres);//��������ۼӺ�
        R[i] = Rres;//��R�����¼��ǰ����ۼӺ�
    }
    res = Lres + R[1];

    for(i = 1; i < len; i++)
    {
       res = compare(res, Lres + R[i]);//���������������ۼӺ͵���0-iԪ�غ�i+1-NԪ�ص������������ۼӺ͵ĺ�
       //����Lres
       Lcur = compare(0, Lcur);
       Lcur += Arr[i];
       Lres = compare(Lcur, Lres);
    }

    return res;
}
