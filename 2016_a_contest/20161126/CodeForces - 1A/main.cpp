#include <iostream>
#include <cstdio>
using namespace std;
__int64 ans;
int main()
{
    __int64 n, m, a, x, y;
    while(~scanf("%I64d%I64d%I64d", &n,&m,&a)){
        if(n%a==0)x=n/a;
        else x=n/a+1;
        if(m%a==0)y=m/a;
        else y=m/a+1;
        ans=x*y;
        printf("%I64d\n", ans);
    }
    return 0;
}
