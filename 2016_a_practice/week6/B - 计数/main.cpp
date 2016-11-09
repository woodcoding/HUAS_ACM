#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

#define MAX 1010

int red[MAX];
int t, k, m, n, u, v, ans;

int main()
{
    scanf("%d", &k);
    while(k--){     //ÓÐ¶¾£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡@
        memset(red, 0, sizeof(red));
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d%d", &u, &v);
            red[u]++;
            red[v]++;
        }
        t = 0;
        for(int i=1;i<=n;i++)t+=red[i]*(n-red[i]-1);
        ans = n*(n-1)*(n-2)/6-t/2;
        printf("%d\n", ans);
    }
    return 0;
}
