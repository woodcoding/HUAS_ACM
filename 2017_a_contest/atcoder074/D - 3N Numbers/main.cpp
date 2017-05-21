#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f;
typedef long long LL;
const int maxn=100005;
LL p1[maxn], p2[maxn];
int n,res[maxn*3];
LL c1, c2, ans;

priority_queue<int, vector<int>, greater<int> > Q1;
priority_queue<int> Q2;

int main()
{
    scanf("%d", &n);
    c1=c2=0;
    for(int i=1;i<=3*n;i++){
        scanf("%lld", &res[i]);
        if(i<=n){
            Q1.push(res[i]);
            c1+=res[i];
        }
        else if(i>2*n){
            Q2.push(res[i]);
            c2+=res[i];
        }
    }
    p1[0]=c1;
    p2[0]=c2;
    for(int i=1;i<=n;i++){
        c1+=res[n+i];
        Q1.push(res[n+i]);
        c1-=Q1.top();
        Q1.pop();
        p1[i]=c1;
        c2+=res[2*n+1-i];
        Q2.push(res[2*n+1-i]);
        c2-=Q2.top();
        Q2.pop();
        p2[i]=c2;
    }
    ans=-INF;
    for(int i=0;i<=n;i++){
        ans=max(ans, p1[i]-p2[n-i]);
    }
    printf("%lld\n", ans);
    return 0;
}
