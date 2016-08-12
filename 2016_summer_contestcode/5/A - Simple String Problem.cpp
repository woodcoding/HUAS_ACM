#include <iostream>
#include <cstdio>
using namespace std;
struct Node{
    int x, y, flag;
};
const int maxn=2000;
int n, d, i, fa[maxn], a, b, c;
Node com[maxn];
bool check(int cx, int cy)
{
    int x1=com[cx].x;
    int x2=com[cy].x;
    int y1=com[cx].y;
    int y2=com[cy].y;
    int dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    int org=d*d;
    if(org>=dis)return true;
    else return false;
}
void Fix()
{
    for(i=1;i<=n;i++)
    {
        if(check(c, i) && com[i].flag)    //如果这台电脑修好了并且距离当前准备修的机子在距离之内
        {
            int fk=fa[i];        //记录这台机子的父节点
            for(int j=1;j<=n;j++)    //把所有和这台机子父节点相同的机子的父节点改为当前准备修的电脑的父节点
            {
                if(fa[j]==fk)fa[j]=fa[c];
            }
        }
    }
    com[c].flag=1;
}
int main()
{
    scanf("%d%d", &n, &d);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d", &com[i].x, &com[i].y);
        com[i].flag=0;
        fa[i]=i;
    }
    char ch[2];
    while(scanf("%s", &ch)!=EOF)
    {
        if(ch[0]=='O')
        {
            scanf("%d", &c);
            Fix();
        }
        if(ch[0]=='S')
        {
            scanf("%d%d", &a, &b);
            if(com[a].flag && com[b].flag && fa[a]==fa[b])    //处在相同集合里面
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}