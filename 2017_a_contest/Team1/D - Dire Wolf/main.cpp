#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int inf=0x3f3f3f3f-10;
const int maxn = 210;
int a[maxn], b[maxn], dp[maxn][maxn];
int t, n;

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d", &b[i]);
        }
        b[0]=b[n+1]=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dp[i][j]=inf;
            }
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=dp[i][n+1]=0;
        }
        for(int len=1;len<=n;len++){        //长度为len
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;              //遍历长度为len时的区间
                for(int k=i;k<=j;k++){      //区间内应该攻击第k只狼(假设其他狼已经died)
                    dp[i][j]=min(dp[i][j], dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
                }
            }
        }
        printf("Case #%d: %d\n", cas, dp[1][n]);
    }
    return 0;
}
