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
const int maxn=100005;

int n;
LL data[maxn], num[maxn];

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%lld", &data[i]);
        }
        LL pos=1, ans=0;
        for(int i=1;i<=9;i++){
            pos*=10;
            memset(num, 0);
            for(int j=0;j<n;j++)num[j]=data[j]%pos;
            sort(num, num+n);
            for(int j=0;j<n;j++){
                int x=n-(lower_bound(num+j+1, num+n, pos-num[j])-num);
                ans+=x;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
