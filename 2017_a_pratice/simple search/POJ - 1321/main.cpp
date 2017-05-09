#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=10;
char mat[maxn][maxn];
int mp[maxn][maxn], row[maxn], col[maxn];
int n, k, ans;

void Init(){
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    memset(mp, -1, sizeof(mp));
    ans=0;
    for(int i=1;i<=n;i++){
        scanf("%s", &mat[i][1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]=='#')mp[i][j]=0;
        }
    }
}

void dfs(int x, int cnt){
    if(cnt==k)ans++;
    if(x>n||cnt==k)return;
    for(int i=1;i<=n;i++){
        if(mp[x][i]==0&&col[i]==-1){
            col[i]=1;
            dfs(x+1, cnt+1);
            col[i]=-1;
        }
    }
    dfs(x+1, cnt);
}

int main()
{
    while(~scanf("%d%d", &n, &k)&&n+k!=-2){
        Init();
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
