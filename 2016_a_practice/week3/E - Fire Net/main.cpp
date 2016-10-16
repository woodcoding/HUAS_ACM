#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

#define MAX 4

char omap[MAX][MAX];
int flag[MAX][MAX];
int n, ans;
int go[4][2]={1,0,-1,0,0,1,0,-1};

bool chkb(int x, int y){    ///检查边界
    if(x<0 || y<0 || x>=n || y>=n)return 0;
    return 1;
}

bool chkg(int x, int y){    ///检查是否可走
    if(flag[x][y] || omap[x][y]=='X')return 0;
    return 1;
}

void dfs(int x, int y, int v){
    if(!chkg(x, y))return;
    int dx, dy;
    int temp[MAX][MAX];
    memcpy(temp, flag, sizeof(temp));
    flag[x][y] = 1;
    v++;
    for(int i=0;i<4;i++){
        for(dx=x+go[i][0],dy=y+go[i][1];chkb(dx, dy) && omap[dx][dy]!='X';dx+=go[i][0],dy+=go[i][1])flag[dx][dy]=1;
    }
    if(v>ans)ans=v;
    for(int i=x*n+y+1;i<n*n;i++)dfs(i/n, i%n, v);
    memcpy(flag, temp, sizeof(flag));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(cin>>n && n){
        ans = 0;
        memset(flag, 0, sizeof(flag));
        for(int i=0;i<n;i++)scanf("%s", &omap[i]);
        for(int i=0;i<n*n;i++)dfs(i/n, i%n, 0);
        cout<<ans<<endl;
    }
    return 0;
}
