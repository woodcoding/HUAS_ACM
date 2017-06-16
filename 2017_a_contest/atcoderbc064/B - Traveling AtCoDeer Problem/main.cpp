#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1005;
int n, ans, data[maxn];

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d", &data[i]);
        }
        ans=0;
        sort(data, data+n);
        for(int i=n-1;i>0;i--){
            ans+=data[i]-data[i-1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
