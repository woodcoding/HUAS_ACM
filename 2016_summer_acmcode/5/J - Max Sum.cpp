#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000+2;
int org[maxn], sum[maxn], b[maxn];
int cas, n, i, j , imax, iflag;

int main()
{
    scanf("%d", &cas);
    for(int k=1;k<=cas;k++)
    {
        scanf("%d", &n);
        for(i=1;i<=n;i++)scanf("%d", &org[i]);
        for(i=1;i<=n;i++)
        {
            sum[i]=org[i];      //��ʼ��������Լ�
            b[i]=i;             //��ʼ��Ҳ���Լ�
        }
        imax=sum[1];            //��ʼ�����ֵ�ͱ�ǵ㶼�ǵ�һ��
        iflag=1;
        for(i=2;i<=n;i++)
        {
            if(sum[i-1]>=0)     //ǰһ����Ϊ�����Ļ����������Ҹı俪ʼ��
            {
                sum[i]=sum[i-1]+org[i];
                b[i]=b[i-1];
            }
            if(sum[i]>imax)     //�ж��Ƿ�ı���״
            {
                imax=sum[i];
                iflag=i;
            }
        }
        printf("Case %d:\n%d %d %d\n", k, imax, b[iflag], iflag);
        if(k!=cas)printf("\n");
    }
    return 0;
}
