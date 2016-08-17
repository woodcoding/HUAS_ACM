#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int n, i, j, tian[maxn], king[maxn], ans, tmin, tmax, kmin, kmax;

bool cmax(int a, int b)
{
    return a>b;
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        ans=0;
        tmax=kmax=0;
        tmin=kmin=n-1;
        for(i=0;i<n;i++)scanf("%d", &tian[i]);
        for(i=0;i<n;i++)scanf("%d", &king[i]);
        sort(tian, tian+n, cmax);
        sort(king, king+n, cmax);
        while(1)
        {
            if(tian[tmin]>king[kmin])
            {
                ans+=200;//最慢的马比，赢
                tmin--;
                kmin--;
            }
            else if(tian[tmin]<king[kmin])
            {
                if(tian[tmin]<king[kmax])ans-=200;//最慢的马比，输
                tmin--;
                kmax++;
            }
            else
            {
                if(tian[tmax]>king[kmax])
                {
                    ans+=200;//最快的马比，赢
                    tmax++;
                    kmax++;
                }
                else if(tian[tmax]<=king[kmax])
                {
                    if(tian[tmin]<king[kmax])ans-=200;//最快的马比，输
                    tmin--;
                    kmax++;
                }
            }
            if(tmax>tmin)break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
