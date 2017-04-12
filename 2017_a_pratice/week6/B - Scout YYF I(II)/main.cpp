#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=40;

double p, dp[maxn], ans;
int n, res[maxn];

int main()
{
    res[0]=0;
    while(~scanf("%d %lf", &n, &p)){
        for(int i=1;i<=n;i++){
            scanf("%d", &res[i]);
        }
        sort(res+1, res+n+1);
        dp[0]=1-p;dp[1]=p*(1-p);
        for(int i=2;i<maxn;i++){
            dp[i]=dp[i-1]*p+dp[i-2]*(1-p);
        }
        ans=1;
        for(int i=1;i<=n;i++){
            if(res[i]-res[i-1]==1){
                ans=0;break;
            }
            int g=res[i]-res[i-1]-2;
            if(g>=maxn)ans*=dp[maxn-1];
            else ans*=dp[g];
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}
