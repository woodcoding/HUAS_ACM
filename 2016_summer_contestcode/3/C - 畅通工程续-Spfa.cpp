#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=200+5;
const int inf=999999;
int n, m, s, t;
vector<pair<int, int> >Node[maxn];
queue<int> Q;
int dis[maxn], inq[maxn];
void Init()
{
    int a, b, x;
    for(int i=0;i<maxn;i++)
    {
        Node[i].clear();
        inq[i]=0;
        dis[i]=inf;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d", &a,&b,&x);
        Node[a].push_back(make_pair(b, x));
        Node[b].push_back(make_pair(a, x));
    }
    scanf("%d%d", &s, &t);
    Q.push(s);
    dis[s]=0;
    inq[s]=1;
}
void Spfa()
{
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inq[u]=0;
        for(int i=0;i<Node[u].size();i++)
        {
            int v=Node[u][i].first;
            if(dis[v]>dis[u]+Node[u][i].second)
            {
                dis[v]=dis[u]+Node[u][i].second;
                if(inq[v]==1)continue;
                Q.push(v);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        Init();
        Spfa();
        if(dis[t]==inf)printf("-1\n");
        else printf("%d\n", dis[t]);
    }
    return 0;
}