#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int maxn=100+10;

int cas, ans, x, n, i, j, k, dp[maxn*2][maxn];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &cas);
    for(k=1;k<=cas;k++)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
            {
                scanf("%d", &x);
                dp[i][j]=dp[i-1][j]+x;
                if(j!=1)dp[i][j]=max(dp[i-1][j-1]+x, dp[i][j]);
            }
        int cur=n+1;
        for(i=n-1;i>=1;i--)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d", &x);
                dp[cur][j]=max(dp[cur-1][j]+x, dp[cur-1][j+1]+x);
            }
            cur++;
        }
        ans = dp[2*n-1][1];
        printf("Case %d: %d\n", k, ans);
    }
    return 0;
}
