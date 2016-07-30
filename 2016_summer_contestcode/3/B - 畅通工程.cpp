#include <iostream>
#include <memory.h>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=100000;
const int maxm=1000;
struct Node
{
    int u, v;
}dist[maxn];

int n, m, i, j;
int parent[maxm];

void Init()
{
    scanf("%d", &m);
    for(i=1;i<=n;i++)parent[i]=i;
    for(i=1;i<=m;i++)
        scanf("%d%d", &dist[i].u, &dist[i].v);
}

int Find(int x)
{
    return x==parent[x]?x:parent[x]=Find(parent[x]);   //找父节点并且使用路径压缩
}

int Process()
{
    for(i=1;i<=m;i++)
    {
        int fa=Find(dist[i].u);
        int fb=Find(dist[i].v);
        if(fa!=fb)
        {
            parent[fa]=fb;
        }
    }
    int sum=0;
    for(i=1;i<=n;i++)
    {
        if(parent[i]==i)sum++;
    }
    return sum-1;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        Init();
        int ans=Process();
        printf("%d\n",  ans);
    }
    return 0;
}
