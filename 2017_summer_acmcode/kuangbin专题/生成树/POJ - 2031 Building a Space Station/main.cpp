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
    int u, v;
    double cost;
    bool operator<(const edge&cmp) const{
        return cost<cmp.cost;
    }
}E[maxn*maxn];

struct point{
    double x, y, z, r;
}p[maxn];

int n, fa[maxn], cnt;

int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}

double Kruskal(){
    double val=0;
    for(int i=0;i<cnt;i++){
        int fu=Find(E[i].u);
        int fv=Find(E[i].v);
        if(fu!=fv){
            fa[fu]=fv;
            val+=E[i].cost;
        }
    }
    return val;
}

int main()
{
    while(~scanf("%d", &n)&&n){
        cnt=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z, &p[i].r);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double d=sqrt(pow(p[i].x-p[j].x, 2)+pow(p[i].y-p[j].y, 2)+pow(p[i].z-p[j].z, 2));
                E[cnt].u=i;
                E[cnt].v=j;
                if(d-(p[i].r+p[j].r)>eps){
                    E[cnt].cost=d-p[i].r-p[j].r;
                }
                else{
                    E[cnt].cost=0;
                }
                cnt++;
            }
        }
        sort(E, E+cnt);
        for(int i=0;i<maxn;i++)fa[i]=i;
        printf("%.3f\n", Kruskal());
    }
    return 0;
}
