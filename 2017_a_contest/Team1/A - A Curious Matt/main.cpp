#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn=10005;
struct Node{
    double t, x;
    bool operator< (const Node &cmp) const {
        return t<cmp.t||t==cmp.t&&x<cmp.x;
    }
}node[maxn];
int t, n;

inline int read(){
    int x=0, f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main()
{
    t=read();
    for(int cas=1;cas<=t;cas++){
        n=read();
        for(int i=0;i<n;i++){
            node[i].t=read();node[i].x=read();
        }
        sort(node ,node+n);
        double v=0;
        for(int i=0;i<n-1;i++){
            double tv=(fabs(node[i].x-node[i+1].x)/fabs(node[i].t-node[i+1].t));
            if(tv>v)v=tv;
        }
        printf("Case #%d: %.2lf\n", cas, v);
    }
    return 0;
}
