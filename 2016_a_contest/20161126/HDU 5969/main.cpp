#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 70
#define LL long long
LL bits[MAX];

int main()
{
    //初始化位数组
    bits[0]=1;
    for(int i=1;i<MAX;i++)bits[i]=bits[i-1]*2;
    int n;
    while(~scanf("%d", &n)){
        while(n--){
            LL l, r, ans, now;
            scanf("%lld%lld", &l,&r);
            ans=l;
            now=0;
            for(int i=MAX-1;i>=0;i--){
                if((r&bits[i])!=0){
                    now+=bits[i];
                    if(now-1>=l)ans=max(ans,(now|now-1));
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
