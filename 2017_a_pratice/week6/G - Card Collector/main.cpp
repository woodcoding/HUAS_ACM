#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=22;
int n, inf;
double p[maxn], dp[1<<maxn];
double nop;

int main()
{
    while(~scanf("%d", &n)){
        inf=1<<n;
        nop = 1;
        for(int i=0;i<n;i++){
            scanf("%lf", &p[i]);
            nop-=p[i];
        }
        dp[inf-1]=0;
        for(int i=inf-2;i>=0;i--){
            dp[i]=1;
            double g=nop;
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0){    //如果没有当前的卡片则加入拿到这张卡后的期望
                    dp[i]+=p[j]*dp[i|(1<<j)];
                }
                else{               //如果当前卡片已经存在或者没卡
                    g+=p[j];
                }
            }
            dp[i]/=(1-g);
        }
        printf("%.4lf\n", dp[0]);
    }
    return 0;
}
