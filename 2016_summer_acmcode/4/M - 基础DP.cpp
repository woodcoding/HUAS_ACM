#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>
using namespace std;

const int maxn=1000+1;
int v[maxn], w[maxn], dp[maxn][maxn], n, m;

void Init()
{
    memset(v, 0, sizeof(v));
    memset(w, 0, sizeof(w));
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)scanf("%d", &v[i]);
    for(int i=1;i<=n;i++)scanf("%d", &w[i]);
}

int main()
{
    int x;
    scanf("%d", &x);
    while(x--)
    {
        Init();
        for(int i=1;i<=n;i++)
            for(int j=m;j>=0;j--)
            dp[i][j]=j<w[i]?dp[i-1][j]:max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
