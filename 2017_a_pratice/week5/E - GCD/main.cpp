#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

const int maxn=100005;
const int maxb=18;
int t, n, q, li, ri, ans;
int dp[maxn][maxb], res[maxn];
map<int, long long> cnt;

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

void rmq(){
    for(int i=1;i<=n;i++){
        dp[i][0]=res[i];
    }
    for(int j=1;j<maxb;j++){
        for(int i=1;i<=n;i++){
            if(i+(1<<j-1)<=n){
                dp[i][j]=gcd(dp[i][j-1], dp[i+(1<<j-1)][j-1]);
            }
        }
    }
}

int calc(int l, int r){
    int j=log(r-l+1)/log(2);
    return gcd(dp[l][j], dp[r-(1<<j)+1][j]);
}

void setTable(){
    cnt.clear();
    for(int i=1;i<=n;i++){
        int j=i;
        int tmp=dp[i][0];
        while(j<=n){
            int l=j,r=n;
            while(l<r){
                int mid=(l+r+1)/2;
                if(calc(i, mid)==tmp)l=mid;
                else r=mid-1;
            }
            cnt[tmp]+=l-j+1;
            tmp=calc(i, l+1);
            j=l+1;
        }
    }
}

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &res[i]);
        }
        rmq();
        setTable();
        scanf("%d", &q);
        printf("Case #%d:\n", cas);
        while(q--){
            scanf("%d%d", &li, &ri);
            ans=calc(li, ri);
            printf("%d %lld\n", ans, cnt[ans]);
        }
    }
    return 0;
}
