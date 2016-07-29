#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn=10000;
const int maxm=100;
struct Node
{
    int u, v, val;
}node[maxn];

int n, num, i, j;
int parent[maxm];

void Init()
{
    num=n*(n-1)/2;
    for(i=0;i<num;i++)
        scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].val);  //获得边权值
    for(i=1;i<=n;i++)
        parent[i]=i;        //初始化父节点为自己
}

bool cmp(Node a, Node b)
{
    return a.val<b.val;     //权值排序，从小到大
}

int Find(int x)
{
    return x==parent[x]?x:parent[x]=Find(parent[x]);    //找父节点并且使用路径压缩
}

int Kruskal()
{
    int sum=0;
    for(i=0;i<num;i++)
    {
        int fa=Find(node[i].u);
        int fb=Find(node[i].v);
        if(fa!=fb)      //不在同一个集合就结合
        {
            sum+=node[i].val;
            parent[fa]=fb;
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        Init();
        sort(node, node+num, cmp);
        int ans=Kruskal();
        printf("%d\n", ans);
    }
    return 0;
}