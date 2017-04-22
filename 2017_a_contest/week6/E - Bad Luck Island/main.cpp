#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=105;
double dp[maxn][maxn][maxn];
int r, s, p;

int main()
{
    while(~scanf("%d%d%d", &r, &s, &p)){
        memset(dp, 0, sizeof(dp));
        dp[r][s][p]=1;
        for(int i=r;i>=1;i--){
            for(int j=s;j>=1;j--){
                for(int k=p;k>=1;k--){
                    double tot=i*j+j*k+k*i;
                    dp[i-1][j][k]+=(1.0*i*k)/tot*dp[i][j][k];
                    dp[i][j-1][k]+=(1.0*i*j)/tot*dp[i][j][k];
                    dp[i][j][k-1]+=(1.0*j*k)/tot*dp[i][j][k];
                }
            }
        }
        double ans1=0, ans2=0, ans3=0;
        for(int i=1;i<maxn;i++){
            for(int j=0;j<maxn;j++){
                ans1+=dp[i][j][0];
                ans2+=dp[0][i][j];
                ans3+=dp[j][0][i];
            }
        }
        printf("%.10f %.10f %.10f\n", ans1, ans2, ans3);
    }
    return 0;
}
