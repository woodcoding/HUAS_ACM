#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=1005;
double dp[maxn][maxn];
int w, b;

int main()
{
    while(~scanf("%d%d", &w, &b)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=w;i++)dp[i][0]=1;
        for(int i=1;i<=w;i++)
        for(int j=1;j<=b;j++)
        {
            dp[i][j]+=1.0*i/(i+j);  //赢
            double bb=1.0*j/(i+j)*(1.0*(j-1)/(i+j-1));  //两只黑色
            if(j>=3){
                dp[i][j]+=bb*(1.0*(j-2)/(i+j-2))*dp[i][j-3];    //跳出黑色
            }
            if(i>=1&&j>=2){
                dp[i][j]+=bb*(1.0*i/(i+j-2))*dp[i-1][j-2];      //跳出白色
            }
          }
        printf("%.9lf\n",dp[w][b]);
    }
    return 0;
}
