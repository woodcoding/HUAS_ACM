#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int x, n, ans;
    while(~scanf("%d",&x) && x)
    {
        n=(x-1)/2;
        ans=(1+n)*n;
        if(x%2)ans-=n;
        printf("%d\n", ans);
    }
    return 0;
}