#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 54322
long long ans[MAX];

int main()
{
    ans[3]=1;
    for(int i=4;i<MAX;i++){
        ans[i]=ans[i-1]+2*(i-2)-1;
    }
    int n;
    while(~scanf("%d", &n)){
        printf("%lld\n", ans[n]);
    }
    return 0;
}
