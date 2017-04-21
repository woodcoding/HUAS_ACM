#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn=5005;

char str[maxn];
int dp[2][maxn];

inline int max(int a, int b){return a>b?a:b;}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", &str[1]);
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str[i]==str[n-j+1]){
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                }
                else{
                    dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
                }
            }
        }
        printf("%d\n", n-dp[n%2][n]);
    }
    return 0;
}
