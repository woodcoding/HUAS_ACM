#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
int main()
{
    int n, now;
    LL x1,x2,diff,tdiff;
    while(~scanf("%d", &n)){
        scanf("%lld", &x1);
        diff=0;
        now=1;
        for(int i=2;i<=n;i++){
            scanf("%lld", &x2);
            tdiff=x2-x1;
            tdiff=tdiff>0?tdiff:-tdiff;
            if(tdiff>diff){
                diff=tdiff;
                now=i;
            }
            x1=x2;
        }
        printf("%d %d\n", now-1, now);
    }
    return 0;
}
