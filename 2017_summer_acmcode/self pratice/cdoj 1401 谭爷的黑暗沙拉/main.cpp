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
#define	FK(no, x) cout<<"Debug:"<<no<<"---"<<x<<"---"<<endl
#define PAIR pair<int, int>
typedef long long LL;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=100000005;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

LL C(LL c, LL r){
    LL ans1=1, ans2=1;
    for(int i=0;i<r;i++){
        ans1*=c--;
        ans2*=r-i;
        LL gcd=__gcd(ans1, ans2);
        ans1/=gcd;
        ans2/=gcd;
    }
    return ans1/ans2;
}

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k)){
        printf("%lld\n", C(k+n-1, n-1));
    }
    return 0;
}
