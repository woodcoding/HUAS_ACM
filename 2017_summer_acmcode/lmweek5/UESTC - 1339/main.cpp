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
#define CLEAR(it) while(!it.empty())it.pop()
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

set<int> l, r;
queue<int> Q;
int n, q, v;

void Balance(){
    if(l.size()+1<r.size()){
        l.insert(*r.begin());
        r.erase(*r.begin());
    }
    else if(l.size()>r.size()){
        r.insert(*l.rbegin());
        l.erase(*l.rbegin());
    }
}

void Push(int x){
    if(r.empty()||x>*r.begin())r.insert(x);
    else l.insert(x);
    Balance();
}

void Del(int x){
    if(x>*l.rbegin())r.erase(x);
    else l.erase(x);
    Balance();
}

int main()
{
    while(~scanf("%d", &n)){
        while(n--){
            scanf("%d", &q);
            if(q==1){
                scanf("%d", &v);
                Q.push(v);
                Push(v);
            }
            else if(q==2){
                v=Q.front();
                Q.pop();
                Del(v);
            }
            else{
                printf("%d\n", *r.begin());
            }
        }
        l.clear();
        r.clear();
        CLEAR(Q);
    }
    return 0;
}
