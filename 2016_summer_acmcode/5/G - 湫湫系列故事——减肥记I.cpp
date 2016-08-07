#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxn=100+10;
const int maxm=200000;
int n, x[maxn], k[maxn], dp[maxm], m, i, j;

int main()
{
    while(~scanf("%d" ,&n)&&n)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)scanf("%d%d",&x[i],&k[i]);
        scanf("%d", &m);
        for(i=1;i<=n;i++)
            for(j=k[i];j<=m;j++)
                dp[j]=max(dp[j], dp[j-k[i]]+x[i]);
        printf("%d\n", dp[m]);
    }
    return 0;
}
