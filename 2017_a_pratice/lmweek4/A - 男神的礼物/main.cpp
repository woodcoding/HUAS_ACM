#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn=105;
int dp[maxn][maxn];
int sum[maxn], n, t;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        sum[0]=0;
        memset(dp, INF, sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d", &sum[i]);
            sum[i]+=sum[i-1];
            dp[i][i]=0;
        }
        for(int r=2;r<=n;r++){
            for(int l=r-1;l>=1;l--){
                for(int g=l;g<r;g++){
                    int cost=((sum[g]-sum[l-1])%100)*((sum[r]-sum[g])%100);
                    dp[l][r]=min(dp[l][r], dp[l][g]+dp[g+1][r]+cost);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
