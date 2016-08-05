#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100;

int main()
{
    int ans, x, n, sum, num[maxn], i, t;
    while(scanf("%d", &n)!=EOF && n)
    {
        sum=ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &num[i]);
            sum^=num[i];
        }
        for(i=0;i<n;i++)
        {
            t=sum^num[i];
            if(t<num[i])ans++;
        }
        if(sum==0)printf("0\n");
        else printf("%d\n", ans);
    }
    return 0;
}
