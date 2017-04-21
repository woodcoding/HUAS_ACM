#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn=1005;

int res[maxn][maxn], sum[maxn][maxn];
int m, n, x, y, t;

inline int max(int a, int b){return a>b?a:b;}
int main()
{
    memset(res, 0, sizeof(res));
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &m, &n, &x, &y);
        memset(sum, 0, sizeof(sum));
        int xx=0;
        for(int i=1;i<=m;i++){
            int tmp=0;
            for(int j=1;j<=n;j++){
                scanf("%d", &res[i][j]);
                xx+=res[i][j];
                tmp+=res[i][j];
                sum[i][j]=sum[i-1][j]+tmp;
            }
        }
        int ans=0;
        for(int i=x;i<=m;i++){
            for(int j=y;j<=n;j++){
                ans=max(ans, sum[i][j]-sum[i-x][j]-sum[i][j-y]+sum[i-x][j-y]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
