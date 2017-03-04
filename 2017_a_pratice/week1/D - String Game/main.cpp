#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

#define MAX 200005

char t[MAX], p[MAX];
int a[MAX], flag[MAX], lent, lenp, l, r, mid, ans;

int check(int x){
    int tans=0;
    memset(flag, 0, sizeof(flag));
    for(int i=0;i<x;i++)flag[a[i]-1]=1;
    for(int i=0;i<lent;i++){
        if(!flag[i] && t[i]==p[tans])tans++;    //如果还没删除并且为p的字串
        if(tans>=lenp)return 1;                 //如果长度大于字串，即为字串
    }
    return 0;
}

int main()
{
    while(~scanf("%s", t)){
        scanf("%s", p);
        lent = strlen(t);
        lenp = strlen(p);
        for(int i=0;i<lent;i++)scanf("%d", &a[i]);
        l=0;
        r=lent-1;
        ans = 0;
        while(l<=r){
            mid = (l+r)>>1;
            if(check(mid)){     //如果存在字串，继续循环
                l = mid+1;
                ans=mid;
            }
            else r = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
