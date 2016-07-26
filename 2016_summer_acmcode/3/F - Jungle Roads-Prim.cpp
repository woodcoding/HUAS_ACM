#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

const int maxn=26+1;
const int INF=999999;
int omap[maxn][maxn];
bool flag[maxn];
int n, i, j;
char ch1, ch2;

void Init()
{
    int num1, num2, x, y;
    memset(omap, INF, sizeof(omap));        //还是给个比较大的值比较靠谱
    memset(flag, 0, sizeof(flag));
    for(i=1;i<=n-1;i++)
    {
       cin>>ch1>>num1;
       for(j=1;j<=num1;j++)
       {
           cin>>ch2>>num2;
           x=ch1-'A'+1;               //字母转化为数字数组
           y=ch2-'A'+1;
           omap[x][y]=omap[y][x]=num2;
       }
    }
}

int Prim()
{   ///不懂的可以去看畅通工程
    int sum=0;
    int minlen, t;
    for(i=1;i<n;i++)
    {
        minlen=1000000;
        for(j=2;j<=n;j++)
        {
            if(!flag[j]&&omap[1][j]<minlen)
            {
                minlen=omap[1][j];
                t=j;
            }
        }
        flag[t]=1;
        sum+=minlen;
        for(j=2;j<=n;j++)
        {
            if(!flag[j] && omap[t][j]<omap[1][j])omap[1][j]=omap[t][j];
        }
    }
    return sum;
}

int main()
{
    while(cin>>n && n)
    {
        Init();
        int ans=Prim();
        cout<<ans<<endl;
    }
    return 0;
}