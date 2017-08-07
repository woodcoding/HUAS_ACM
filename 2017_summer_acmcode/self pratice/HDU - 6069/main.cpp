#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define    GE() printf(">----------\n")
#define    IN() freopen("in.txt","r",stdin)
#define    OUT() freopen("out.txt","w",stdout)
#define MP pair<int, int>
typedef long long LL;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1000005;

int t;
LL l, r, k, ans;
LL prime[maxn], vis[maxn], cp;
LL cnt[maxn], num[maxn], tot;

void Prime(){
    mem(vis, 0),cp=0;
    for(int i=2;i<maxn;i++){
        if(!vis[i])prime[cp++]=i;
        for(int j=0;j<cp&&i<maxn/prime[j];j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    Prime();
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &l, &r, &k);
        ans=0;
        if(l==1)ans=1, l++;
        tot=r-l+1;
        for(int i=0;i<tot;i++){
            num[i]=l+i;         //暂存l-r区间数
            cnt[i]=1;           //初始化为1，统计每个数的d(nk)
        }
        for(int i=0;prime[i]*prime[i]<=r;i++){      //遍历区间内所有质数
            LL now=ceil(l*1.0/prime[i])*prime[i];       //计算质数最低开始数
            for(now;now<=r;now+=prime[i]){          //质数递增
                LL c=0;
                while(num[now-l]%prime[i]==0){      //区间数分解
                    num[now-l]/=prime[i];
                    c++;
                }
                cnt[now-l]*=(k*c+1)%mod;
                cnt[now-l]%=mod;
            }
        }
        for(int i=0;i<tot;i++){
            if(num[i]!=1)ans+=(cnt[i]*(k+1))%mod;
            else ans+=cnt[i];
            ans%=mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
