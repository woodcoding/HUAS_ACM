#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define memset(a,b) memset(a, b, sizeof(a))
const int maxn=12;
const int n=10;
struct Node{
    int cnt, cost;
    int v[maxn];
    Node(){
        cnt=cost=0;
        memset(v,0);
    }
};

int data[maxn][maxn];
Node dp[maxn][maxn];

int main()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &data[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int v=data[i][j];
            dp[i][j-1].cost+=v;
            if(dp[i][j-1].v[v]==0){
                dp[i][j-1].cnt++;
                dp[i][j-1].v[v]=1;
            }
            dp[i-1][j].cost+=v;
            if(dp[i-1][j].v[v]==0){
                dp[i-1][j].cnt++;
                dp[i-1][j].v[v]=1;
            }
            if(dp[i][j-1].cnt==dp[i-1][j].cnt){
                if(dp[i][j-1].cost<dp[i-1][j].cost){
                    dp[i][j]=dp[i][j-1];
                }
                else dp[i][j]=dp[i-1][j];
            }
            else if(dp[i][j-1].cnt>dp[i-1][j].cnt){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%d\n", dp[n][n].cost);
    return 0;
}
