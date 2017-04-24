#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=105;
int res[maxn][maxn];
int dp[maxn];
int m, n;

inline int max(int a, int b){return a>b?a:b;}

int main()
{
    while(~scanf("%d%d", &n, &m)&&n+m){
        memset(res, 0, sizeof(res));
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d", &res[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=m;j>0;j--){
                for(int k=1;k<=j;k++){
                    dp[j]=max(dp[j], dp[j-k]+res[i][k]);
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
