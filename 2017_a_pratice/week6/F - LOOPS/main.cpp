#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=1005;
const double magic=2.0;
int r, c;
double dp[maxn][maxn];
double res[maxn][maxn][3];

int main()
{
    while(~scanf("%d%d", &r, &c)){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                for(int k=0;k<3;k++){
                    scanf("%lf", &res[i][j][k]);
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int i=r;i>0;i--){
            for(int j=c;j>0;j--){
                if(i==r&&j==c)continue;
                double ps,pr,pd;
                ps=res[i][j][0];
                pr=res[i][j][1];
                pd=res[i][j][2];
                if(ps==1.0)dp[i][j]=0;
                else{
                    dp[i][j]=(pr*dp[i][j+1]+pd*dp[i+1][j]+2)/(1-ps);
                }
            }
        }
        printf("%.3lf\n", dp[1][1]);
    }
    return 0;
}
