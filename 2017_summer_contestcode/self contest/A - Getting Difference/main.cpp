#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n, k;
int a[maxn];

int main()
{
    while(~scanf("%d%d", &n, &k)){
        int ans=0, g=0;
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
            g=__gcd(g, a[i]);
        }
        sort(a, a+n);
        if(k<=a[n-1]&&k%g==0)cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
