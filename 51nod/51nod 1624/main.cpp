#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n, p;

int data[4][maxn];
int sum[4][maxn];
set<int> val;
//sum[1][x]-sum[2][x-1]+sum[2][y]-sum[3][y-1]+sum[3][n]

int main()
{
    while(~scanf("%d%d", &n, &p)){
        memset(data, 0, sizeof(data));
        val.clear();
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&data[i][j]);
                data[i][j]+=data[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            sum[1][i]=(data[1][i]-data[2][i-1])%p;
            sum[2][i]=(data[2][i]-data[3][i-1]+data[3][n])%p;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            val.insert(sum[1][i]);
            int tmp=(p-1-sum[2][i])%p;
            set<int>::iterator it=val.lower_bound(tmp);
            if(*it==tmp)ans=max(ans, (sum[2][i]+*it)%p);
            else if(it!=val.begin())ans=max(ans, (sum[2][i]+*(--it))%p);
        }
        printf("%d\n", ans);
    }
    return 0;
}
