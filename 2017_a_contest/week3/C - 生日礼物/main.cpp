#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX 1000005

struct Node{
    int ca, pos;
    bool operator<(const Node &x) const{
        return pos<x.pos;
    }
}node[MAX];

int n, k, t, cnt, ans, l, r, vis[MAX];

int main()
{
    scanf("%d%d", &n, &k);
    cnt = 0;
    for(int i=1;i<=k;i++){
        scanf("%d", &t);
        while(t--){
            scanf("%d", &node[cnt].pos);
            node[cnt++].ca=i;
        }
    }
    sort(node, node+n);
    memset(vis, 0, sizeof(vis));
    l=r=cnt=0;
    long long ans=1e11;
    for(;r<n;){
        while(cnt<k&&r<n){
            vis[node[r].ca]++;
            if(vis[node[r].ca]==1)cnt++;
            r++;
        }
        ans=min(ans, (long long)node[r-1].pos-node[l].pos);
        vis[node[l].ca]--;
        if(vis[node[l].ca]==0)cnt--;
        l++;
    }
    printf("%lld\n", ans);
    return 0;
}
