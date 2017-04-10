#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 10005
int res[MAX];

int main()
{
    int n, k, m;
    while(~scanf("%d%d%d", &n, &k, &m)&&n+k+m){
        int b=m%n, cnt=0;
        if(!b)b=1;
        else b++;
        for(int i=0;i<n-1;i++){
            res[cnt++]=b++;
            if(b==m)b++;
            if(b==n+1)b=1;
        }
        int ans=0;
        n--;
        for(int i=2;i<=n;i++){
            ans=(ans+k)%i;
        }
        printf("%d\n", res[ans]);
    }
    return 0;
}
