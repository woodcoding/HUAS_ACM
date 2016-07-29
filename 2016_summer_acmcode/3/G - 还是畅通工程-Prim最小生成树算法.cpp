#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxm=100+1;

int n, num, i, j;
int node[maxm][maxm], dis[maxm], flag[maxm];

void Init()
{
    int x, y, val;
    num=n*(n-1)/2;
    memset(flag, 0, sizeof(flag));      //初始化每个点都不在集合中
    memset(node, INF, sizeof(node));    //初始化各个距离为无穷大
    memset(dis, -1, sizeof(dis));       //初始化为-1意思为当前点到集合没有距离
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d", &x,&y,&val);  //获得边权值
        node[x][y]=node[y][x]=val;
    }
}

int Prim()
{
    int sum=0;
    dis[1]=0;
    flag[1]=1;
    for(i=2;i<=n;i++)       //初始化其他各点到起点集合的位置
        dis[i]=node[1][i];
    for(i=1;i<n;i++)
    {
        int tmin=999999, cur=-1;
        for(j=2;j<=n;j++)
        {
            if(!flag[j]&&(dis[j]<tmin))    //找距离当前集合最小的权
                {
                    tmin=dis[j];
                    cur=j;
                }
        }
        flag[cur]=1;    //将这个权加入集合中
        sum+=dis[cur];
        for(j=2;j<=n;j++)       //更新各个点到集合的距离
        {
            if(!flag[j]&&node[cur][j]<dis[j])
                dis[j]=node[cur][j];
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        Init();
        int ans=Prim();
        printf("%d\n", ans);
    }
    return 0;
}
