#include <iostream>
#include <cstdio>
using namespace std;

#define LL long long
#define MAX 10005
const int mod=9901;

int pri[MAX], cnt[MAX];
int a, b;

LL mmod(LL x, LL y){
    LL val=1;
    while(y){
        if(y&1)val=(val*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return val;
}

LL sum(LL p, LL n){
    if(n==0)return 1;
    if(n%2)
        return (sum(p, n/2) * (1+mmod(p, n/2+1))) % mod;
    else
        return (sum(p, n/2-1) * (1+mmod(p, n/2+1)) + mmod(p, n/2)) % mod;
}

int main()
{
    while(~scanf("%d%d", &a, &b)){
        int k=0;
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                pri[k++]=i;
                while(a%i==0){
                    cnt[k-1]++;
                    a/=i;
                }
            }
        }
        if(a!=1){
            pri[k]=a;
            cnt[k++]=1;
        }
        int ans=1;
        for(int i=0;i<k;i++){
            ans=ans*(sum(pri[i], cnt[i]*b)%mod)%mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
