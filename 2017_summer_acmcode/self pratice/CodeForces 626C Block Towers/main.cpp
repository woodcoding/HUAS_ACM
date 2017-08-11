/*
#include <iostream>
#include <cstdio>
using namespace std;

const int L=1, R=1e7;
int n, m;

bool check(int x){
    int num2=x/2;
    int num3=x/3;
    int num6=x/6;
    if(num2>=n&&num3>=m&&num2+num3-num6>=n+m)return 1;
    return 0;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        int l=L, r=R, mid, ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid))ans=mid, r=mid-1;
            else l=mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        n*=2, m*=3;
        for(int i=6;i<=min(n, m);i+=6){
            if(n<=m)n+=2;
            else m+=3;
        }
        printf("%d\n", max(n, m));
    }
    return 0;
}
