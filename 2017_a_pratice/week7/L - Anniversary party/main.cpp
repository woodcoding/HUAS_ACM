#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxn = 6005;
int n, res[maxn], in[maxn], dp[maxn][2], root;
vector<int> go[maxn];
inline int max(int a, int b){return a>b?a:b;}

void dfs(int u){
    dp[u][0]=0;
    dp[u][1]=res[u];
    for(int i=0;i<go[u].size();i++){
        int v=go[u][i];
        dfs(v);
        dp[u][0]+=max(dp[v][0], dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}

int main()
{
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            scanf("%d", &res[i]);
            dp[i][0]=dp[i][1]=0;
            go[i].clear();
            in[i]=0;
        }
        int l, k;
        while(scanf("%d%d", &l, &k)&&l!=0&&k!=0){
            in[l]++;
            go[k].push_back(l);
        }
        for(int i=1;i<=n;i++){
            if(!in[i]){
                root=i;break;
            }
        }
        dfs(root);
        printf("%d\n", max(dp[root][0], dp[root][1]));
    }
    return 0;
}
