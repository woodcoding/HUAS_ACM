#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define memset(a,b) memset(a, b, sizeof(a))
#define INF 0x3f3f3f3f
const int inf=0x3f3f3f3f;
const int maxn=12;
const int n=10;

int data[maxn][maxn], dp[maxn][maxn][1<<10];

int main()
{
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            scanf("%d", &data[i][j]);
        }
    }
    memset(dp, INF);
    dp[1][1][1<<data[1][1]]=data[1][1];
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(i==1&&j==1)continue;
            for(int k=0;k<=1023;k++){
                dp[i][j][k|1<<data[i][j]]=min(dp[i][j][k], min(dp[i][j-1][k], dp[i-1][j][k])+data[i][j]);
            }
        }
    }
    printf("%d\n", dp[10][10][1023]);
    return 0;
}
