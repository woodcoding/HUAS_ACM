#include <iostream>
#include <cstdio>
#include <memory.h>
#include <vector>
using namespace std;

#define M 200005
int n, m, k, u, v, cnt;
int pa[M*2], dk[M*2], ans[M*2], vis[M*2];
vector<int> star[M*2];

int Find(int x){
    return x==pa[x]?x:pa[x]=Find(pa[x]);
}

void add(int u){
    for(int i=0;i<star[u].size();i++){
        int v=star[u][i];
        if(!vis[v]){
            int fu=Find(u);
            int fv=Find(v);
            if(fu!=fv){
                pa[fu]=fv;
                cnt--;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis));
    cnt = 0;
     for(int i=0;i<n;i++){
        pa[i]=i;
    }
    for(int i=0; i<m; i++){
        scanf("%d%d", &u, &v);
        star[u].push_back(v);
        star[v].push_back(u);
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf("%d", &dk[i]);
        vis[dk[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            add(i);
            cnt++;
        }
    }
    ans[k]=cnt;
    for(int i=k-1;i>=0;i--){
        add(dk[i]);
        cnt++;
        ans[i]=cnt;
        vis[dk[i]]=0;
    }
    for(int i=0;i<=k;i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}
