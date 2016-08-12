#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1000;

int n, ans, x, dp[maxn], flag;

int main()
{
    while(~scanf("%d", &n) && n)
    {
        dp[0]=0;
        ans=0;
        for(int i=1;i<maxn;i++)dp[i]=30000;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            sort(dp,dp+ans+1);
            flag=0;
            for(int j=0;j<=ans;j++)
            {
                if(dp[j]>=x)
                {
                    dp[j]=x;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans++;
                dp[ans]=x;
                flag=1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
