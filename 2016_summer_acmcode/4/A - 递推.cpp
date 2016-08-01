#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int imod=1007;
const int maxn=2000+1;
int x, m, n, c[maxn][maxn];

void Init()
{    ///打表
    memset(c, 0, sizeof(c));
    for(int i=0;i<maxn;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]%imod+c[i-1][j]%imod)%imod;   //一边模一遍存
    }
}

int main()
{
    Init();
    scanf("%d", &x);
    while(x--)
    {
        scanf("%d%d", &m, &n);
        printf("%d\n", c[n][m]);
    }
    return 0;
}
