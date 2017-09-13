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

int res[]={0,4,4,6,6,7,8,8};


int main()
{
    int x, T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &x);
        int ans;
        if(x<8)ans=res[x];
        else{
            int num=sqrt(x/2);
            int s=num*num*2;
            if(x==s)ans=num*4;
            else if(x<=s+num-0.5)ans=num*4+1;
            else if(x<=s+2*num)ans=num*4+2;
            else if(x<=s+3*num-0.5)ans=num*4+3;
            else ans=num*4+4;
        }
        printf("%d\n", ans);
    }
    return 0;
}
