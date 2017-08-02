#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define	GE() printf(">----------\n")
#define	IN() freopen("in.txt","r",stdin)
#define	OUT() freopen("out.txt","w",stdout)
#define	FK(x, y) cout<<"Debug:"<<y<<"---"<<x<<"---"<<endl
#define MP pair<int, int>
typedef long long LL;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=105;

struct edge{
    int v, cost;
    edge(int to, int c){v=to, cost=c;}
    edge(){}
    bool operator<(const edge&cmp) const{
        return cost>cmp.cost;
    }
};

vector<edge> E[maxn];
priority_queue<edge> que;
int n, m;
int u, v, cost;
int vis[maxn];

int Prim(){
    int ans=0;
    vis[1]=1;
    for(int i=0;i<E[1].size();i++){
        que.push(E[1][i]);
    }
    while(!que.empty()){
        edge top=que.top();
        que.pop();
        if(vis[top.v])continue;
        ans+=top.cost;
        vis[top.v]=1;
        for(int i=0;i<E[top.v].size();i++)
            que.push(E[top.v][i]);
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n)&&n){
        scanf("%d", &m);
        for(int i=0;i<maxn;i++)E[i].clear();
        while(!que.empty())que.pop();
        mem(vis, 0);
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &u, &v, &cost);
            E[u].push_back(edge(v, cost));
            E[v].push_back(edge(u, cost));
        }
        printf("%d\n", Prim());
    }
    return 0;
}
