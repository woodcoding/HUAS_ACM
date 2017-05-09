#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 0x3f3f3f3f
#define LL long long
const int inf= 0x3f3f3f3f;
const int maxn=3005;
struct Ca{
    int pos, val;
    bool operator<(const Ca &cmp) const{
        return pos<cmp.pos;
    }
}ca[maxn];
LL n, pd, dp[maxn], ans;

int main()
{
    while(~scanf("%d", &n)){
        pd=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d", &ca[i].pos, &ca[i].val);
        }
        sort(ca+1, ca+1+n);
        for(int i=2;i<=n;i++)pd+=ca[i].pos-ca[1].pos;
        memset(dp, MAX, sizeof(dp));
        dp[1]=ca[1].val+pd;
        ans=dp[1];
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=min(dp[i], dp[j]+ca[i].val-(n-i+1)*(ca[i].pos-ca[j].pos));
            }
            ans=min(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
