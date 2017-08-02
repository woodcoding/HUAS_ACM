#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=28;
struct edge{
    edge(int v, int c){to=v,cost=c;}
    edge(){}
    int to, cost;

    bool operator<(const edge &cmp)const{
        return cost>cmp.cost;
    }
};

char cu, cv;
int n, ku, kv;
int vis[maxn];

priority_queue<edge> que;
vector<edge> E[maxn];

int Prim(){
    int ans=0;
    vis[0]=1;
    for(int i=0;i<E[0].size();i++){
        que.push(E[0][i]);
    }
    while(!que.empty()){
        edge e=que.top();
        que.pop();
        if(vis[e.to])continue;
        vis[e.to]=1;
        ans+=e.cost;
        for(int i=0;i<E[e.to].size();i++){
            que.push(E[e.to][i]);
        }
    }
    return ans;
}

int main(){
    while(~scanf("%d", &n)&&n){
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<maxn;i++)E[i].clear();
        while(!que.empty())que.pop();
        for(int i=0;i<n-1;i++){
            scanf("%s%d", &cu, &ku);
            for(int j=0;j<ku;j++){
                scanf("%s%d", &cv, &kv);
                E[cu-'A'].push_back(edge(cv-'A', kv));
                E[cv-'A'].push_back(edge(cu-'A', kv));
            }
        }
        printf("%d\n", Prim());
    }
}


/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100;

struct edge{
    int u, v, cost;
    bool operator<(const edge &cmp) const{
        return cost<cmp.cost;
    }
}E[maxn];

int n, ku, kv, cnt;
char cu, cv;
int fa[maxn];

int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}

int Kruskal(){
    int ans=0;
    for(int i=0;i<cnt;i++){
        int fu=Find(E[i].u);
        int fv=Find(E[i].v);
        if(fu!=fv){
            fa[fu]=fv;
            ans+=E[i].cost;
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n)&&n){
        cnt=0;
        for(int i=0;i<maxn;i++)fa[i]=i;
        for(int i=0;i<n-1;i++){
            scanf("%s%d", &cu, &ku);
            for(int j=0;j<ku;j++){
                scanf("%s%d", &cv, &kv);
                E[cnt].u=cu-'A';
                E[cnt].v=cv-'A';
                E[cnt].cost=kv;
                cnt++;
            }
        }
        sort(E, E+cnt);
        printf("%d\n", Kruskal());
    }
    return 0;
}
*/
