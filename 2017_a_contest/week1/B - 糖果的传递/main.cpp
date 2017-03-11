#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1000005
int res[MAX];
int val[MAX];

int n, all;
long long ans, avg;

int main()
{
    while(~scanf("%d", &n)){
        ans = 0;
        avg = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &res[i]);
            avg+=res[i];
        }
        avg/=n;
        for(int i=1;i<=n;i++)val[i]=val[i-1]+res[i]-avg;
        sort(val+1, val+n+1);
        avg = val[n/2+1];
        for(int i=1;i<=n;i++)ans+=abs(val[i]-avg);
        printf("%lld\n", ans);
    }
    return 0;
}
