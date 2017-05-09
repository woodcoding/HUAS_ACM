#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1000005;
int num[maxn];
int t, n;

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d", &n);
        for(int i=0;i<n;i++)scanf("%d", &num[i]);
        int now=num[n-1], ans=0;
        for(int i=n-2;i>=0;i--){
            if(num[i]>now)ans++;
            else now=num[i];
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
