#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 105
bool omap[MAX][MAX];
int n, m, a, b;
int main()
{
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<m;i++){
            scanf("%d%d", &a, &b);
            omap[a][b] = 1;
        }
        for(int k=1;k<=n;k++){
            for(int u=1;u<=n;u++){
                for(int v=1;v<=n;v++){
                    omap[u][v]=(omap[u][v]||(omap[u][k]&&omap[k][v]));
                }
            }
        }
        int ans=0, cnt;
        for(int u=1;u<=n;u++){
            cnt=0;
            for(int v=1;v<=n;v++){
                if(omap[u][v]||omap[v][u])cnt++;
            }
            if(cnt==n-1)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
