#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAX 100005
#define LL long long
int c[5], d[5], tot, s;
LL f[MAX];
LL ans;
int main()
{
    for(int i=1; i<5; i++)scanf("%d",&c[i]);
    scanf("%d", &tot);
    f[0]=1;
    for(int i=1; i<5; i++)
    {
        for(int j=c[i]; j<100001; j++)
        {
            f[j]+=f[j-c[i]];
        }
    }
    while(tot--)
    {
        for(int i=1; i<5; i++)scanf("%d", &d[i]);
        scanf("%d", &s);
        ans=f[s];
        for(int i=1; i<5; i++)
        {
            if(s>=(d[i]+1)*c[i])ans-=f[s-(d[i]+1)*c[i]];
        }
        for(int i=1; i<4; i++)for(int j=i+1; j<5; j++)
            {
                if(s>=(d[i]+1)*c[i]+(d[j]+1)*c[j])ans+=f[s-(d[i]+1)*c[i]-(d[j]+1)*c[j]];
            }
        for(int i=1; i<3; i++)for(int j=i+1; j<4; j++)for(int k=j+1; k<5; k++)
                {
                    if(s>=(d[i]+1)*c[i]+(d[j]+1)*c[j]+(d[k]+1)*c[k])ans-=f[s-(d[i]+1)*c[i]-(d[j]+1)*c[j]-(d[k]+1)*c[k]];
                }
        if(s>=(d[1]+1)*c[1]+(d[2]+1)*c[2]+(d[3]+1)*c[3]+(d[4]+1)*c[4])ans+=f[s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[3]+1)*c[3]-(d[4]+1)*c[4]];
        printf("%lld\n", ans);
    }
    return 0;
}
