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

int n, m, s, e;     //n:�ڵ�����m:������ s:��㣬t:�յ�
int u, v, a, b, t;  //u:��ʼ�㣬v:�����㣬a:����ʱ�䣬b:�ر�ʱ�䣬t:ͨ��ʱ��
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
        if(t<=a)        //����ʱ��Ҫ���ڻ����ͨ��ʱ��
        {
            vnode[++cnt]=unode[u];  //ʼ�ձ��ֿ��Ի�����ͨ�ڵ�Ĺ���u->v(u)->v(v(u))->v(v(v(u)))
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
        for(j=unode[cur];j!=-1;j=vnode[j])      //����������ͨ��·
        {
            int curv=dist[j].v;
            int open=dist[j].open;
            int close=dist[j].close;
            int go=dist[j].go;
            tt=now%(open+close);
            if(tt+go<=open)     //����ֱ��ͨ��
            {
                if(now+go<dis[curv])
                    dis[curv]=now+go;
            }
            else                //�ȴ�ͨ��
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
