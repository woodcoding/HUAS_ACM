#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define LL long long
map<LL, LL>node;

int q, com;
LL u, v, w;

int main()
{
    while(~scanf("%d", &q)){
        while(q--){
            scanf("%d", &com);
            if(com==1){
                scanf("%lld%lld%lld", &u, &v, &w);
                while(u!=v){
                    if(u>v){
                        node[u]+=w;
                        u/=2;
                    }
                    else{
                        node[v]+=w;
                        v/=2;
                    }
                }
            }
            else{
                scanf("%lld%lld", &u, &v);
                LL ans=0;
                while(u!=v){
                    if(u>v){
                        ans+=node[u];
                        u/=2;
                    }
                    else{
                        ans+=node[v];
                        v/=2;
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
