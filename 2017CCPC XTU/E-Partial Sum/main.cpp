#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int maxn=100005;

int n, m, c;
LL sum[maxn], ans;

int main()
{
    while(~scanf("%d%d%d", &n, &m, &c)){
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d", &sum[i]);
            sum[i]+=sum[i-1];
        }
        sort(sum, sum+n+1);
        ans=0;
        for(int i=0;i<m;i++){
            LL val=abs(sum[n-i]-sum[i])-c;
            if(val<=0)break;
            ans+=val;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
