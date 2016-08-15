#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

const int maxn=20+5;
int ans[maxn], flag[maxn];
int ss[50];
int n, cas=0;

void dfs(int x, int cnt)
{
    if(cnt>1 && ss[x+ans[cnt-1]]==0)return;
    if(cnt==n && ss[x+ans[1]]==0)return;
    flag[x]=1;
    ans[cnt]=x;
    if(cnt==n && ss[x+ans[1]]==1)
    {
        for(int k=1;k<=n;k++)
        {
            printf("%d", ans[k]);
            if(k==n)printf("\n");
            else printf(" ");
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(!flag[j])
        {
            flag[j]=1;
            dfs(j, cnt+1);
            flag[j]=0;
        }
    }
    return;
}

int main()
{
    memset(ss, 0, sizeof(ss));
    ss[1]=ss[2]=ss[3]=ss[5]=ss[7]=ss[11]=ss[13]=ss[17]=ss[19]=ss[23]=ss[29]=ss[31]=ss[37]=ss[41]=ss[43]=ss[47]=1;
    while(~scanf("%d", &n))
    {
        printf("Case %d:\n", ++cas);
        for(int i=0;i<maxn;i++){ans[i]=0;flag[i]=0;}
        for(int i=1;i<=n;i++)
        {
            dfs(i, 1);
        }
        printf("\n");
    }
    return 0;
}
