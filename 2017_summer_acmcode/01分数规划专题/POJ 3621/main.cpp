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
#define MP pair<int, int>
typedef long long LL;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-3;
const int maxn=5005;

int n, m;
double dis[maxn];
int inq[maxn], cnt[maxn], w[maxn];
vector<pair<int, int> > E[maxn];
queue<int> Q;

bool spfa(double mid){
    while(!Q.empty())Q.pop();
    for(int i=1;i<=n;i++){
        dis[i]=0;inq[i]=1;cnt[i]=1;
        Q.push(i);
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        inq[u]=0;
        for(int i=0;i<E[u].size();i++){
            int v=E[u][i].first;
            double val=w[v]*1.0-1.0*mid*E[u][i].second;
            if(dis[v]<dis[u]+val){
                dis[v]=dis[u]+val;
                if(++cnt[v]>=n)return 1;
                if(inq[v])continue;
                Q.push(v);
                inq[v]=1;
            }
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<=n;i++)E[i].clear();
        for(int i=1;i<=n;i++)scanf("%d", &w[i]);
        int u, v, cost;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d", &u, &v, &cost);
            E[u].push_back(make_pair(v, cost));
        }
        double l=0, r=1000, mid;
        while(r-l>eps){
            mid=(l+r)/2;
            if(spfa(mid))l=mid;
            else r=mid;
        }
        printf("%.2f\n", l);
    }
    return 0;
}
