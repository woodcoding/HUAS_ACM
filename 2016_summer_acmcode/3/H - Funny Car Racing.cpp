#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

const int maxn=100000+5;
const int INF=99999999;
struct Node
{
    int v,open,close,go;
}dist[maxn];

int n, m, s, e;     //n:节点数，m:行数， s:起点，t:终点
int u, v, a, b, t;  //u:开始点，v:结束点，a:开启时间，b:关闭时间，t:通过时间
int dis[maxn], vis[maxn], unode[maxn], vnode[maxn];
int cnt, i, j;

void Init()
{
    memset(vis, 0, sizeof(vis));
    memset(unode, -1, sizeof(unode));
    for(i=0;i<=n;i++)dis[i]=INF;
    cnt=0;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d%d%d", &u,&v,&a,&b,&t);
        if(t<=a)        //开放时间要大于或等于通过时间
        {
            vnode[++cnt]=unode[u];  //始终保持可以互相连通节点的关联u->v(u)->v(v(u))->v(v(v(u)))
            unode[u]=cnt;
            dist[cnt].v=v;
            dist[cnt].open=a;
            dist[cnt].close=b;
            dist[cnt].go=t;
        }
    }
}

void Dij()
{
    dis[s]=0;
    int now, twait, tt;
    for(i=1;i<=n;i++)
    {
        int cur=-1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&(cur==-1||dis[j]<dis[cur]))cur=j;
        }
        vis[cur]=1;
        now=dis[cur];
        for(j=unode[cur];j!=-1;j=vnode[j])      //走完所有连通的路
        {
            int curv=dist[j].v;
            int open=dist[j].open;
            int close=dist[j].close;
            int go=dist[j].go;
            tt=now%(open+close);
            if(tt+go<=open)     //可以直接通过
            {
                if(now+go<dis[curv])
                    dis[curv]=now+go;
            }
            else                //等待通过
            {
                twait=open+close-tt;
                if(now+go+twait<dis[curv])
                    dis[curv]=now+go+twait;
            }
        }
    }
}

int main()
{
    int icase=0;
    while(scanf("%d %d %d %d",&n,&m,&s,&e)!=EOF)
    {
        Init();
        Dij();
        printf("Case %d: %d\n", ++icase, dis[e]);
    }
    return 0;
}
