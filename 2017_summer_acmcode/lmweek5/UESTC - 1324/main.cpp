#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100005;
const int maxnd=maxn*3;
int n, q, t, p, x;
long long ans;
int w[maxnd];

struct Node{
    int l, r;
    long long v;
}node[maxnd];

void Build(int id, int l, int r){
    node[id].l=l;
    node[id].r=r;
    node[id].v=0;
    if(l==r){
        w[l]=id;
        return;
    }
    int mid=(l+r)/2;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
}

void Update(int id, long long v){
    if(id==w[p])node[id].v+=v;
    else node[id].v=max(node[id].v, v);
    if(id==1)return;
    Update(id/2, node[w[p]].v);
}

void Query(int id, int l, int r){
    if(node[id].l==l&&node[id].r==r){
        ans=max(ans, node[id].v);
        return;
    }
    id=id*2;
    if(l<=node[id].r){
        if(r<=node[id].r)Query(id, l, r);
        else Query(id, l, node[id].r);
    }
    id+=1;
    if(r>=node[id].l){
        if(l>node[id].l)Query(id, l, r);
        else Query(id, node[id].l, r);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    Build(1, 1, n);
    while(q--){
        scanf("%d%d%d", &t, &p, &x);
        if(t==1){
            Update(w[p], x);
        }
        else{
            ans=0;
            Query(1, p, x);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
