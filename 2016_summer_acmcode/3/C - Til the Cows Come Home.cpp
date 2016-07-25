#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=1000+1;
const int INF=9999999;
int omap[maxn][maxn], dis[maxn];
bool vis[maxn];
int t, n, i, j;
int x, y, len;

void Init()
{
    memset(omap, INF, sizeof(omap));
    memset(dis, INF, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d", &x, &y, &len);
        if(len<omap[x][y])
        {
            omap[x][y]=omap[y][x]=len;      //去重
        }
    }
}

void Process()
{
    dis[1]=0;   //第一个点距离自己为0
    for(i=1;i<=n;i++ )        //循环N个点
    {
        int cur=-1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&(cur==-1||dis[j]<dis[cur]))  //找距离1最小的最远位置，这个值从他自己开始找
                cur=j;
        }
        vis[cur]=1;     //标记当前位置已经被访问
        for(j=1;j<=n;j++)
        {
            //如果一个位置没有被访问并且通过标记位置间接获得了比当前位置更短的距离
            if(!vis[j]&&dis[j]>dis[cur]+omap[cur][j])
                dis[j]=dis[cur]+omap[cur][j];
        }
    }
}

int main()
{
    while(scanf("%d%d", &t, &n)!=EOF)
    {
        Init();
        Process();
        printf("%d\n", dis[n]);
    }
    return 0;
}
