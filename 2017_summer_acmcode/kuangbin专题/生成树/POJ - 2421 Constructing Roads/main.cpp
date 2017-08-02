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
#define	FK(x, y) cout<<"Debug:"<<x<<"---"<<y<<"---"<<endl
#define MP pair<int, int>
typedef long long LL;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=105;

struct edge{
    int u, v, cost;
    bool operator<(const edge&cmp) const{
        return cost<cmp.cost;
    }
}E[maxn*maxn];

int n, q, cnt;
int fa[maxn];

int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}

bool Union(int x, int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy){
        fa[fx]=fa[fy];
        return 1;
    }
    return 0;
}

int Kruskal(){
    int val=0;
    for(int i=0;i<cnt;i++){
        if(Union(E[i].u, E[i].v)){
            val+=E[i].cost;
        }
    }
    return val;
}

int main()
{
    while(~scanf("%d", &n)){
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                E[cnt].u=i;
                E[cnt].v=j;
                scanf("%d", &E[cnt].cost);
                if(i==j)continue;
                cnt++;
            }
        }
        for(int i=1;i<=n;i++)fa[i]=i;
        scanf("%d", &q);
        int u, v;
        while(q--){
            scanf("%d%d", &u, &v);
            Union(u, v);
        }
        sort(E, E+cnt);
        printf("%d\n", Kruskal());
    }
    return 0;
}
