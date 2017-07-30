#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn=200005;
int d1[maxn];
int c1, c2, n, m;

map<int, int> go;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        c1=0;
        go.clear();
        int u, v;
        for(int i=0;i<m;i++){
            scanf("%d%d", &u, &v);
            if(u==1||v==1){
                if(u==1)d1[c1++]=v;
                else d1[c2++]=u;
            }
            if(u==n||v==n){
                if(u==n)go[v]=1;
                else go[u]=1;
            }
        }
        int ans=0;
        for(int i=0;i<c1;i++){
            int t=d1[i];
            if(go[t]){
                ans=1;break;
            }
        }
        if(ans)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
