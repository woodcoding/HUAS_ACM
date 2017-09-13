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

typedef long long LL;
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
#define memset(a,b) memset(a,b,sizeof(a))
#define	GE() printf(">----------\n")
#define	IN() freopen("in.txt","r",stdin)
#define	OUT() freopen("out.txt","w",stdout)
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1005;

int n, m, r, ans;
int E[maxn][maxn], data[maxn];

int main()
{
    int n;
    while(~scanf("%d%d%d", &n, &m, &r)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                E[i][j]=inf;
                if(i==j)E[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            scanf("%d", &data[i]);
        }
        int u, v, cost;
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &u, &v, &cost);
            E[u][v]=E[v][u]=cost;
        }
        for(int k=1;k<=n;k++){
            for( int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    E[i][j]=min(E[i][j], E[i][k]+E[k][j]);
                }
            }
        }
        sort(data, data+r);
        ans=0;
        for(int i=1;i<r;i++){
            ans+=E[data[i-1]][data[i]];
        }
        while(next_permutation(data, data+r)){
            int tans=0;
            for(int i=1;i<r;i++){
                tans+=E[data[i-1]][data[i]];
            }
            ans=min(ans, tans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
