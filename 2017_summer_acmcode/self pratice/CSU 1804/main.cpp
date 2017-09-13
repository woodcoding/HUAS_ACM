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
#include <list>
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
const int maxn=100005;

vector<int> E[maxn];
LL a[maxn], b[maxn], sum[maxn];
int in[maxn];
int n, m;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        memset(in, 0);
        memset(sum, 0);
        for(int i=1;i<=n;i++)E[i].clear();

        for(int i=1;i<=n;i++){
            scanf("%d%d", &a[i], &b[i]);
        }
        int u, v;
        for(int i=0;i<m;i++){
            scanf("%d%d", &v, &u);
            E[u].push_back(v);
            in[v]++;
        }

        LL ans=0;
        queue<int> que;
        for(int i=1;i<=n;i++){
            if(in[i]==0)que.push(i);
        }

        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=0;i<E[u].size();i++){
                int v=E[u][i];
                sum[v]+=sum[u]+b[u];
                sum[v]%=mod;
                if(--in[v]==0)que.push(v);
            }
        }

        for(int i=1;i<=n;i++){
            ans+=a[i]*sum[i];
            ans%=mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
