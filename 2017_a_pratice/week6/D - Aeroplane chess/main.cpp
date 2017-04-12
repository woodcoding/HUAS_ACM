#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=100005;
int n, m, x, y, fly[maxn];
double dp[maxn];

int main()
{
    while(~scanf("%d%d", &n, &m) && n+m){
        memset(fly, 0, sizeof(fly));
        for(int i=0;i<m;i++){
            scanf("%d%d", &x, &y);
            fly[x]=y;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=n-1;i>=0;i--){
            if(fly[i]){
                dp[i]=dp[fly[i]];
            }
            else{
                for(int j=1;j<=6;j++){
                    dp[i]+=dp[i+j]/6.0;
                }
                dp[i]+=1;
            }
        }
        printf("%.4lf\n", dp[0]);
    }
    return 0;
}
