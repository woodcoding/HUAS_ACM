#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=200005;
typedef long long LL;
struct Node{
    int s, t, c;
    bool operator<(const Node &cmp) const{
        return c>cmp.c;
    }
}node[maxn];
int n;
LL ans;

int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d", &node[i].s, &node[i].t);
            node[i].c=abs(node[i].s-node[i].t);
        }
        sort(node, node+n);
        ans=0;
        LL now=0;
        for(int i=0;i<n;i++){
            if(node[i].s>now){
                ans+=node[i].s-now;
                now=node[i].s;
            }
            now-=node[i].t;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
