#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=30;
int mat[maxn][maxn], clr[maxn];
int t, n, m, num;

bool dfs(int x, int y){
    int ls=n*m-(x-1)*m+y-1;
    for(int i=1;i<=num;i++){
        if(clr[i]>(ls+1)/2)return 0;
    }
    for(int i=1;i<=num;i++){
        if(clr[i]&&mat[x][y-1]!=i&&mat[x-1][y]!=i){
            clr[i]--;
            mat[x][y]=i;
            if(x==n&&y==m)return 1;
            int nx=x, ny=x;
            if(y==m){nx=x+1;ny=1;}
            else{nx=x;ny=y+1;}
            if(!dfs(nx, ny))
                clr[i]++;
            else return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d", &n, &m, &num);
        for(int i=1;i<=num;i++){
            scanf("%d", &clr[i]);
        }
        printf("Case #%d:\n", cas);
        memset(mat, -1, sizeof(mat));
        if(dfs(1, 1)){
            printf("YES\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    printf("%d", mat[i][j]);
                    printf("%s", j==m?"\n":" ");
                }
            }
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
