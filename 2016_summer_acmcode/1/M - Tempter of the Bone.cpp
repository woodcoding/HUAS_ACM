#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, m, t, i, j, sx,sy,ex,ey, flag;
int go[4][2]={1,0,0,1,-1,0,0,-1};
const int maxn=10;
char omap[maxn][maxn];

void Init()
{
    flag=0;
    for(i=0;i<maxn;i++)for(j=0;j<maxn;j++)omap[i][j]='X';
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        cin>>omap[i][j];
        switch(omap[i][j])
        {
        case 'S':
            omap[i][j]='X';
            sx=i;
            sy=j;
            break;
        case 'D':
            omap[i][j]='.';
            ex=i;
            ey=j;
            break;
        case '.':
            omap[i][j]='.';
            break;
        }
    }
}

void Dfs(int x, int y, int cur)
{
    if(x==ex && y==ey && cur==t){flag=1;return;}
    //int temp=(t-cur)-(abs(ex-x)+abs(ey-y));
    //当前剩余时间-当前剩余步数
    //if(temp<0||temp%2)return;
    for(int k=0;k<4;k++)
    {
        int tx=x+go[k][0];
        int ty=y+go[k][1];
        if(omap[tx][ty]!='X')
        {
            omap[tx][ty]='X';
            Dfs(tx, ty, cur+1);
            if(flag)return;
            omap[tx][ty]='.';
        }
    }
    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d%d%d", &n,&m,&t) && n+m+t)
    {
        Init();
        if((sx+sy+ex+ey+t)%2==0)Dfs(sx,sy,0);
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
