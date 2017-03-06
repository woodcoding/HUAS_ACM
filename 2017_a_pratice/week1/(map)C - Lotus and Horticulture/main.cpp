#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define LL long long
map<int, LL> res;

int t, n, l, r, a, b, c;

LL ans, now;

int main()
{
    scanf("%d", &t);
    while(t--){
        res.clear();
        ans = 0;
        now = 0;
        scanf("%d", &n);
        while(n--){
            scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
            res[0]+=c;
            res[l*2] += a-c;
            res[r*2+1] +=b-a;
        }
        for(map<int , LL>::iterator it=res.begin();it!=res.end();it++){
            now+=it->second;
            ans=ans>now?ans:now;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
