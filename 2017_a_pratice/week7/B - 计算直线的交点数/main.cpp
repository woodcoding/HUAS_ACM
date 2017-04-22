#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn=25;
const int maxm=200;

int ans[maxm], up, n;
int dp[maxn][maxm];

inline int max(int a, int b){return a>b?a:b;}

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;dp[1][0]=1;
    for(int i=2;i<=20;i++){
        dp[i][0]=1;
        for(int j=1;j<i;j++){
            for(int k=0;k<=dp[j][0];k++){
                if(dp[j][k]){   //如果前j条的k个交点组合存在
                    dp[i][(i-j)*j+k]=1;
                    dp[i][0]=max(dp[i][0], (i-j)*j+k);
                }
            }
        }
    }
    while(~scanf("%d",&n)){
        for(int i=0;i<=dp[n][0];i++){
            if(dp[n][i]){
                printf("%d", i);
                if(i!=dp[n][0])printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
