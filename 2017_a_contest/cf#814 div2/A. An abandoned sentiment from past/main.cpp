#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1000;
int a[maxn];
int b[maxn];
int n, k;

bool cmp(int t1, int t2){
    return t1>t2;
}

int main()
{
    while(~scanf("%d%d", &n, &k)){
        bool ans=0;
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        for(int i=1;i<=k;i++)scanf("%d", &b[i]);
        sort(b+1, b+1+k, cmp);
        int now=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                a[i]=b[now++];
            }
        }
        now=0;
        for(int i=1;i<=n;i++){
            if(a[i]<now){
                ans=1;break;
            }
            now=a[i];
        }
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
