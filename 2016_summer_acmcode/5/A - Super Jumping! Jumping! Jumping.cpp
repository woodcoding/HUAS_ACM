#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000+10;
int org[maxn], sum[maxn];
int n, i, j, ans, imax;
int main()
{
    while(~scanf("%d", &n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d", &org[i]);
            sum[i]=org[i];
        }
        ans=sum[0];
        for(i=1;i<n;i++)
        {
            imax=0;
            for(j=0;j<i;j++)
            {
                if(org[i]>org[j] && org[i]+sum[j]>sum[i])
                    sum[i]=org[i]+sum[j];
            }
            if(sum[i]>ans)ans=sum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
