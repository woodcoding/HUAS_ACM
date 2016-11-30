#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MAX 100010
int n, x, maxn, ans;
int res[MAX], vis[MAX], num[MAX];

void add(int bit){
    int now=bit, cnt=0;
    while(now<=maxn){
        vis[now]++;
        num[now]+=cnt++;
        now<<=1;
    }
    now=bit, cnt=0;
    while(now){
        if(now%2==1 && now!=1){
            now>>=1;
            vis[now]++;
            num[now]+=++cnt;
            int tnow=now,tcnt=cnt;
            while((tnow<<1)<=maxn){
                tnow<<=1;
                vis[tnow]++;
                num[tnow]+=++tcnt;
            }
        }
        else{
            now>>=1;
            vis[now]++;
            num[now]+=++cnt;
        }
    }
}

int main()
{
    while(~scanf("%d", &n)){
        maxn=0;
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d", &res[i]);
            maxn=max(maxn, res[i]);
        }
        for(int i=0;i<n;i++)add(res[i]);
        ans=1e6;
        for(int i=0;i<MAX;i++){
            if(vis[i]==n)ans=min(ans, num[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
