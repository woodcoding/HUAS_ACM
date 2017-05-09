#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=45;
const int maxm=1000005;
int res[maxn], dp[2][maxm*2];
int t, n, m, cas=1;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
            scanf("%d", &res[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<maxm;j++){
                dp[i%2][j]+=dp[(i-1)%2][j];
                dp[i%2][j^res[i]]+=dp[(i-1)%2][j];
            }
            for(int j=0;j<maxm;j++){
                dp[!(i%2)][j]=0;
            }
        }
        long long ans=0;
        for(int i=m;i<maxm;i++)
            ans+=dp[n%2][i];
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
