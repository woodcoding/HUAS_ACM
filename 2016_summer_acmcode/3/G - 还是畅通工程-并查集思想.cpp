#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Village
{
    int a;
    int b;
    int len;        //两个村庄的距离
};

const int maxn=5000;        //这是给出边数的数目，不是村庄的数目
Village village[maxn];
int flag[maxn];
int a, b, len, i, j, n, num;

void Init()
{
    num=n*(n-1)/2;
    for(i=1;i<=num;i++)     //获得初始数据
        scanf("%d%d%d", &village[i].a, &village[i].b, &village[i].len);
    for(i=1;i<=n;i++)flag[i]=i;     //初始化父节点为自己
}

bool cmp(Village cmpa, Village cmpb)
{
    return cmpa.len<cmpb.len;       //距离从小到大排列
}

int Find(int x)
{   //找根节点
    if(flag[x]==x)return x;
    flag[x]=Find(flag[x]);
    return flag[x];
}

int Process()
{
    int sum=0;
    for(i=1;i<=num;i++)
    {
        int fa=Find(village[i].a);
        int fb=Find(village[i].b);
        if(fa==fb)continue;
        else
        {
            sum+=village[i].len;        //根节点不同，加入距离
            if(fa>fb)       //大于小于都行，加入同一个集合
                flag[fb]=fa;
            else
                flag[fa]=fb;
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)!=EOF &&n)
    {
        Init();
        sort(village+1, village+1+num, cmp);
        int ans=Process();
        printf("%d\n", ans);
    }
    return 0;
}
