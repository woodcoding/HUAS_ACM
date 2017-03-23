#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAX 100010

int sub[MAX], flag[MAX];
int ans, t, n, m, sum;

int main()
{
    scanf("%d", &t);
    while(t--){
        memset(flag, 0, sizeof(flag));
        ans=0;
        sum=0;
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++){
            scanf("%d", &sub[i]);
            sum=(sum+sub[i])%m;
            if(flag[sum]||sum==0)ans=1;
            flag[sum]=1;
        }
        printf("%s\n", ans?"YES":"NO");
    }
    return 0;
}

