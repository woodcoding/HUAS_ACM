#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;

LL now, ans;
int n, x;

int main()
{
    while(~scanf("%d", &n)){
        ans=now=0;
        while(n--){
            scanf("%d", &x);
            if(x>now)ans+=(x-now);
            now=x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
