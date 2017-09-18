#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=10005;

struct Node{
    int l, r, v;
}node[maxn*4];

int n, q, l, r, data[maxn], id[maxn];

void BuildTree(int idx, int l, int r){
    node[idx].l=l;
    node[idx].r=r;
    node[idx].v=0;
    if(l==r){
        id[l]=idx;
        return;
    }
    int mid=(l+r)/2;
    BuildTree(idx*2, l, mid);
    BuildTree(idx*2+1, mid+1, r);
}

void update(int idx, int v){
    node[idx].v=max(node[idx].v, v);
    if(idx==1)return;
    update(idx/2, v);
}

int query(int l, int r, int L, int R, int idx){
    if(l==L&&r==R)return node[idx].v;
    int mid=(L+R)/2;
    if(r<=mid)return query(l, r, L, mid, idx*2);
    else if(l>mid)return query(l, r, mid+1, R, idx*2+1);
    else{
        return max(query(l, mid, L, mid, idx*2), query(mid+1, r, mid+1, R, idx*2+1));
    }
}

int main()
{
    while(~scanf("%d", &n)){
        BuildTree(1, 1, n);
        for(int i=1;i<=n;i++){
            scanf("%d", &data[i]);
            update(id[i], data[i]);
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &l, &r);
            printf("%d\n", query(l+1, r+1, 1, n, 1));
        }
    }
    return 0;
}
