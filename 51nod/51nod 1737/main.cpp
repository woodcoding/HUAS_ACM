/*
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn=1e5+5;
const LL inf=0x3f3f3f3f3f3f3f3f;

int n, u, v, son, s;
LL cost;
LL dis[maxn], inq[maxn];
vector<pair<int, LL> > E[maxn];

int node[maxn], vis[maxn];

struct Spfa{
    void init(){
        for(int i=0;i<maxn;i++){
            dis[i]=inf;
            E[i].clear();
            inq[i]=0;
        }
    }

    LL spfa(LL s){
        queue<LL> Q;
        dis[s]=0;
        inq[s]=1;
        Q.push(s);
        while(!Q.empty()){
            LL u=Q.front();
            Q.pop();
            inq[u]=0;
            for(int i=0;i<E[u].size();i++){
                LL v=E[u][i].first;
                if(dis[v]>dis[u]+E[u][i].second){
                    dis[v]=dis[u]+E[u][i].second;
                    if(inq[v])continue;
                    Q.push(v);
                    inq[v]=1;
                }
            }
        }
        return dis[n];
    }
};

int dfs(int u){
    vis[u]=1;
    node[u]=0;
    int maxv=-1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i].first;
        if(vis[v])continue;
        dfs(v);
        node[u]+=node[v]+1;
        maxv = max(maxv, node[v]+1);
    }
    maxv=max(maxv, n-node[u]-1);
    if(maxv<son){
        s=u;
        son=maxv;
    }
    return 0;
}

int main()
{
    Spfa calc;
    while(~scanf("%d", &n)){
        calc.init();
        for(int i=0;i<n-1;i++){
            scanf("%d%d%lld", &u, &v, &cost);
            E[u].push_back(make_pair(v, cost));
            E[v].push_back(make_pair(u, cost));
        }
        memset(vis, 0, sizeof(vis));
        memset(node, 0, sizeof(node));
        son=maxn;
        dfs(1);
        calc.spfa(s);
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans+=dis[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int n, u, v, cost;
int data[maxn], son[maxn], vis[maxn];
vector<pair<int, int> > E[maxn];
LL ans;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void Init(){
    for(int i=0;i<=n;++i)E[i].clear();
    memset(vis, 0, sizeof(vis));
    ans=0;
}

void dfs(int u){
    son[u]=1;
    vis[u]=1;
    int len=E[u].size();
    for(int i=0;i<len;++i){
        int v=E[u][i].first;
        if(vis[v])continue;
        dfs(v);
        son[u]+=son[v];
        LL cost=E[u][i].second;
        ans+=cost*min(son[v], n-son[v]);
    }
}

int main(){
    while(~scanf("%d", &n)){
        Init();
        for(int i=0;i<n-1;++i){
            u=read();v=read();cost=read();
            E[u].push_back(make_pair(v, cost));
            E[v].push_back(make_pair(u, cost));
        }
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
