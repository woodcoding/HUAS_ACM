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
#define	FK(x) cout<<"Debug:---"<<x<<"---"<<endl
#define PAIR pair<int, int>
typedef long long LL;
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=100005;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Node{
    int t, v;
    bool operator<(const Node &cmp) const{
        return t<cmp.t||(t==cmp.t&&v>cmp.v);
    }
}node[maxn];
int n;

priority_queue<int, vector<int>, greater<int> > all;

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d", &node[i].t);
        }
        for(int i=0;i<n;i++){
            scanf("%d", &node[i].v);
        }
        sort(node, node+n);
        int ans=0,now=0;
        for(int i=0;i<n;i++){
            if(now+1<=node[i].t){
                all.push(node[i].v);
                now++;
            }
            else if(node[i].v>all.top()){
                all.pop();
                all.push(node[i].v);
            }
        }
        while(!all.empty()){
            ans+=all.top();
            all.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}
