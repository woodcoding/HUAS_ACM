#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAX 50005

int t, n, l, r, a, b, c;
long long ans, base;

struct Res{
    double pos;
    int val;

    bool operator<(const Res&x){
        return pos<x.pos;
    }
}res[MAX*2];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans=0;
        base=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
            base+=c;
            res[i].pos=l;
            res[i].val=a-c;
            res[i+n].pos=r+0.5;
            res[i+n].val=b-a;
        }
        sort(res, res+n*2);
        for(int i=0;i<n*2;i++){
            base+=res[i].val;
            while(i+1<n*2&&res[i].pos==res[i+1].pos){
                i++;
                base+=res[i].val;
            }
            if(base>ans)ans=base;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
