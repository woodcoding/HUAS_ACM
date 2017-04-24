#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn=605;

int n, m, have, tot, up, down;
double dp[maxn], ans[maxn];

int main()
{
    while(~scanf("%d%d", &n, &m)){
        memset(ans, 0, sizeof(ans));
        for(int i=1;i<=6;i++)ans[i]=1.0/6;
        down=1;up=6;
        for(int i=1;i<n;i++){
            for(int j=down;j<=up;j++){
                for(int k=1;k<=6;k++){
                    dp[j+k]+=ans[j]*1.0/6;
                }
            }
            down++;up+=6;
            for(int j=down;j<=up;j++){
                ans[j]=dp[j];
                dp[j]=0;
            }
        }
//        double t=0;
//        for(int i=down;i<=up;i++){
//            t+=ans[i];
//        }
        if(m>=n&&m<=n*6)
            printf("%.2lf\n", ans[m]*100);
        else printf("0.00\n");
    }
    return 0;
}
