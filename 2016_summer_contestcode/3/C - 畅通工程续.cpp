#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=200+5;
const int inf=999999;
int n, m, a, b, x, s, t, i, j;
int dist[maxn][maxn], flag[maxn], dis[maxn];

void Init()
{
    memset(flag, 0, sizeof(flag));
    for(i=0;i<maxn;i++)dis[i]=-1;
    for(i=0;i<maxn;i++)for(j=0;j<maxn;j++)
    {
        if(i==j)dist[i][j]=0;
        else dist[i][j]=inf;
    }
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>x;
        if(dist[a][b]>x)dist[a][b]=dist[b][a]=x;
    }
    cin>>s>>t;
}

void Dij()
{
    dis[s]=0;
    for(i=1;i<=n;i++)
    {
        int tmin=inf, cur;
        for(j=0;j<n;j++)
        {
            if(!flag[j]&&(dis[j]!=-1&&dis[j]<tmin))
            {
                tmin=dis[j];
                cur=j;
            }
        }
        flag[cur]=1;
        for(j=0;j<n;j++)
        {
            if(!flag[j]&&dist[cur][j]<inf&&(dis[j]==-1||dis[j]>dis[cur]+dist[cur][j]))
                dis[j]=dis[cur]+dist[cur][j];
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(cin>>n>>m)
    {
        Init();
        Dij();
        cout<<dis[t]<<endl;
    }
    return 0;
}
