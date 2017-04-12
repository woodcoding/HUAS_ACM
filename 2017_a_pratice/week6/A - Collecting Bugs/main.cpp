#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=1005;
int n, s;
double dp[maxn][maxn];
double p1, p2, p3, p4, all;

int main()
{
    while(~scanf("%d%d", &n, &s)){
        dp[n][s]=0;
        all=n*s;
        for(int i=n;i>=0;i--){
            for(int j=s;j>=0;j--){
                if(i==n&&j==s)continue;
                p1=(i*j)/all;
                p2=(i*(s-j))/all;
                p3=((n-i)*j)/all;
                p4=((n-i)*(s-j))/all;
                dp[i][j]=(1.0+p2*dp[i][j+1]+p3*dp[i+1][j]+p4*dp[i+1][j+1])/(1.0-p1);
            }
        }
        printf("%.4lf\n", dp[0][0]);
    }
    return 0;
}
