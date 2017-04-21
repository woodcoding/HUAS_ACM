#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn = 2005;

int n, m, k;
double p1, p2, p3, p4, p21, p31, p41;
double dp[maxn][maxn], c[maxn];
double eps = 1e-5;

int main()
{
    while(~scanf("%d%d%d%lf%lf%lf%lf", &n, &m, &k, &p1, &p2, &p3, &p4)){
        if(p4<eps){
            printf("0.00000\n");continue;
        }
        p21 = p2/(1-p1);
        p31 = p3/(1-p1);
        p41 = p4/(1-p1);
        dp[1][1]=p41/(1-p21);
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(j==1)c[j]=p41;
                else if(j<=k)c[j]=p31*dp[i-1][j-1]+p41;
                else c[j]=p31*dp[i-1][j-1];
            }
            double tmp=0, pp=1;
            for(int j=i;j>=1;j--){
                tmp+=c[j]*pp;
                pp*=p21;
            }
            dp[i][i]=tmp/(1-pp);
            dp[i][1]=p21*dp[i][i]+p41;
            for(int j=2;j<i;j++){
                dp[i][j]=p21*dp[i][j-1]+c[j];
            }
        }
        printf("%.5f\n", dp[n][m]);
    }
    return 0;
}
