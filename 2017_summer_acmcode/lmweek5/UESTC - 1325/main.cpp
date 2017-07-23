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

struct Node{
    int l,r,v,lazy; //v为没有普法人数
}node[maxn*10];
struct Option{
    int cmd, l, r;
}op[maxn*3];

int n, q;
int p[maxn*3];
map<int, int> idx;

void Push_down(int id){     //lazy下放
    node[id<<1].lazy=node[id<<1|1].lazy=1;
    node[id<<1].v=node[id<<1|1].v=0;  //下级全部普法
    node[id].lazy=0;
}

void Build(int id, int l, int r){
    node[id].l=l;
    node[id].r=r;
    node[id].v=p[r]-p[l]+1;
    node[id].lazy=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    Build(id<<1, l, mid);
    Build(id<<1|1, mid+1, r);
}

void Update(int id, int l, int r){
    if(node[id].l==l&&node[id].r==r){
        node[id].v=0;
        node[id].lazy=1;
        return;
    }
    if(node[id].lazy)Push_down(id);
    int mid=(node[id].l+node[id].r)>>1;
    if(r<=mid)Update(id<<1, l, r);
    else if(l>mid)Update(id<<1|1, l, r);
    else{
        Update(id<<1, l, mid);
        Update(id<<1|1, mid+1, r);
    }
    node[id].v=node[id<<1].v+node[id<<1|1].v;
}

int Query(int id, int l, int r){
    if(node[id].l==l&&node[id].r==r){
        return node[id].v;
    }
    if(node[id].lazy)Push_down(id);
    int mid=(node[id].l+node[id].r)>>1;
    if(r<=mid)return Query(id<<1, l, r);
    else if(l>mid)return Query(id<<1|1, l, r);
    return Query(id<<1, l, mid)+Query(id<<1|1, mid+1, r);
}

int main()
{
    int t, l, r, cnt=0;
    scanf("%d%d", &n, &q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d", &op[i].cmd, &op[i].l, &op[i].r);
        p[++cnt]=op[i].l;
        p[++cnt]=op[i].r;
        p[++cnt]=op[i].r+1;
    }
    sort(p+1, p+cnt+1);
    cnt=unique(p+1, p+cnt+1)-(p+1);
    for(int i=1;i<=cnt;i++){
        idx[p[i]]=i;
    }
    Build(1, 1, cnt);
    for(int i=0;i<q;i++){
        t=op[i].cmd;
        l=idx[op[i].l];
        r=idx[op[i].r];
        if(op[i].cmd==1){
            Update(1, l, r);
        }
        else printf("%d\n", Query(1, l, r));
    }
    return 0;
}
