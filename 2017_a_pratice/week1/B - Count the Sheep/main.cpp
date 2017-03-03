#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 200005

const int len=100000;

vector<int> res[MAX];

int t, n, m, k, x, y;
long long ans;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        ans = 0;
        int tmax=n>m?n:m;
        for(int i=1;i<=tmax;i++){
            res[i].clear();
            res[i+len].clear();
        }
        while(k--){
            scanf("%d%d", &x, &y);
            res[x].push_back(y+len);
            res[y+len].push_back(x);
        }
        for(int i=1;i<=n;i++){
            int now=res[i].size();
            for(int j=0;j<now;j++){
                int border = res[res[i][j]].size();
                ans+=(now-1)*(border-1);
            }
        }
        printf("%lld\n", ans*2);
    }
    return 0;
}
