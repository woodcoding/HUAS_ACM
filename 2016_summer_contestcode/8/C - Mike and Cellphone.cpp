#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <queue>
using namespace std;
char num[10];
int omap[6][6];
int go[10][2];
int cnt=0;
int x;

struct Point{
    int x, y;
}myqueue[10];

void Init()
{
    memset(omap, -1, sizeof(omap));
    int add=1;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            {
                go[add][0]=i;
                go[add][1]=j;
                omap[i][j]=add++;
            }
    omap[4][2]=0;
    go[0][0]=4;
    go[0][1]=2;
}


bool dfs(int q)
{
    for(int i=0;i<cnt;i++)
    {
        int dx=go[q][0]+myqueue[i].x;
        int dy=go[q][1]+myqueue[i].y;
        if(dx>4 || dx<1 || dy>3 || dy<1 || omap[dx][dy]==-1)return 0;
        q=omap[dx][dy];
    }
    return 1;
}


bool Process()
{
    int t1, t2;
    t1=num[0]-'0';
    cnt=0;
    for(int i=1;i<x;i++)
    {
        t2=num[i]-'0';
        Point temp;
        temp.x=go[t2][0]-go[t1][0];
        temp.y=go[t2][1]-go[t1][1];
        myqueue[cnt++]=temp;
        t1=t2;
    }
    int tcnt=0;
    for(int i=0;i<10;i++)
    {
        if(dfs(i))tcnt++;
    }
    if(tcnt==1)return 1;
    else return 0;
}


int main()
{
    Init();
    while(cin>>x)
    {
        scanf("%s", &num);
        if(x==1)printf("NO\n");
        else
        {
            if(Process())printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
