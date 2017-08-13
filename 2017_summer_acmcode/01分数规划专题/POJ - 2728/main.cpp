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
const double eps=1e-5;
const int maxn=1005;

int x[maxn], y[maxn], h[maxn], vis[maxn], cost[maxn][maxn];
double len[maxn][maxn], val[maxn][maxn], dis[maxn];
int n;

bool Prim(double mid){
    double sum=0;
    int u=1;
    mem(vis, 0);
    for(int i=1;i<=n;i++)dis[i]=inf;
    vis[u]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            val[i][j]=cost[i][j]-mid*len[i][j];
        }
    }
    for(int i=1;i<n;i++){
        double small=inf;
        int now=-1;
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            dis[j]=min(dis[j], val[u][j]);
            if(dis[j]<small){
                small=dis[j], now=j;
            }
        }
        vis[now]=1;sum+=dis[now];
        u=now;
    }
    return sum>=0;
}


int main()
{
    while(~scanf("%d", &n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d", &x[i], &y[i], &h[i]);
        }
        double l=0, r=1e8, mid;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cost[i][j]=cost[j][i]=abs(h[i]-h[j]);
                len[i][j]=len[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+1.0*(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        while(r-l>eps){
            mid=(l+r)/2;
            if(Prim(mid))l=mid;
            else r=mid;
        }
        printf("%.3f\n", l);
    }
    return 0;
}

