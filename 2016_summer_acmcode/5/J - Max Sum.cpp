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
            sum[i]=org[i];      //初始化最大都是自己
            b[i]=i;             //开始点也是自己
        }
        imax=sum[1];            //初始化最大值和标记点都是第一个
        iflag=1;
        for(i=2;i<=n;i++)
        {
            if(sum[i-1]>=0)     //前一个数为整数的话加上来并且改变开始点
            {
                sum[i]=sum[i-1]+org[i];
                b[i]=b[i-1];
            }
            if(sum[i]>imax)     //判断是否改变现状
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
