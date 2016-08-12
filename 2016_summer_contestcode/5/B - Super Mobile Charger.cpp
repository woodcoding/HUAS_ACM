#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int x, int y)
{
    return x>y;
}

int main()
{
    const int maxn=100+10;
    int cas, N, M, power[maxn], i, ans, t;
    scanf("%d", &cas);
    for(int k=1;k<=cas;k++)
    {
        scanf("%d%d", &N,&M);
        for(i=0;i<N;i++)scanf("%d", &power[i]);
        sort(power, power+N, cmp);
        ans=0;
        for(i=0;i<N;i++)
        {
            t=100-power[i];
            if(power[i]!=100 && M>=t)
            {
                power[i]+=t;
                M-=t;
            }
            if(power[i]==100)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
