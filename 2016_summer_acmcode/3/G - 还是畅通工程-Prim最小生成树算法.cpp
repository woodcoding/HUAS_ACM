#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

const int maxn=100+2;
int omap[maxn][maxn];   //村庄距离记录图
bool flag[maxn];         //村庄访问标记记录
int n, i, j;

void Init()
{
    int num=n*(n-1)/2;      //数据组数
    int x, y, len;
    memset(omap, 0, sizeof(omap));      //初始化清空数组
    memset(flag, 0, sizeof(flag));
    for(i=1;i<=num;i++)
    {
        scanf("%d%d%d", &x,&y,&len);
        omap[x][y]=omap[y][x]=len;      //x->y的距离==y->x的距离
    }
}

int Prim()
{
    int sum=0;
    int minlen, t;
    for(i=1;i<n;i++)        //注意，循环n-1次
    {
        minlen=100000;
        for(j=2;j<=n;j++)
        {
            if(!flag[j] && omap[1][j]<minlen)     //如果这个点没有被访问，并且它小于最小值
            {
                minlen=omap[1][j];
                t=j;        //当前点赋值给t；
            }
        }
        flag[t]=1;      //标记当前点已经被访问
        sum+=minlen;
        //cout<<"-->minlen:"<<minlen<<endl;
        for(j=2;j<=n;j++)
        {
            //如果当前点到下个点的距离小于根到他的距离那么更新根到下个点的距离
            if(!flag[j] && omap[t][j]<omap[1][j])omap[1][j]=omap[t][j];
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
