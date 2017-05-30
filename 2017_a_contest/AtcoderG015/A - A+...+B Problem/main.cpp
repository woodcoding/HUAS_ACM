#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

LL ans;
int n, a, b;

int main()
{
    while(~scanf("%d%d%d", &n, &a, &b)){
        LL minx=a+b+(n-2ll)*a;
        LL maxx=a+b+(n-2ll)*b;
        ans=maxx-minx+1;
        if(a>b)ans=0;
        if(ans<0)ans=0;
        cout<<ans<<endl;

    }
    return 0;
}
