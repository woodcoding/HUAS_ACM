#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 100000*3
#define MMAX 100010
struct Node{
    int r, l, sq;
    long long v;
};

Node node[MAX];
int res[MMAX], rnum=0;
long long ans;

int n, m, x, l ,r;


void BuildTree(int id, int l, int r){   //����
    node[id].l = l;
    node[id].r = r;
    node[id].sq = 0;
    if(l == r){
        node[id].v = res[++rnum];
        if(res[rnum]<=1)node[id].sq = 1;
        return;
    }
    int mid = (l+r)>>1;
    BuildTree(id<<1, l, mid);
    BuildTree((id<<1)+1, mid+1, r);
    node[id].v = node[id<<1].v + node[(id<<1)+1].v;
}

void Query(int id, int l, int r){   //����
    if(node[id].l==l&&node[id].r==r){
        ans+=node[id].v;
        return;
    }
    id=id<<1;
    if(l<=node[id].r){//���������漰
        if(r<=node[id].r)Query(id, l, r);   //ȫ���漰
        else Query(id, l, node[id].r);
    }
    id += 1;
    if(r>=node[id].l){//���������漰
        if(l>=node[id].l)Query(id, l, r);   //ȫ���漰
        else Query(id, node[id].l, r);
    }
}

void Update(int id, int x, int y){//����
    if(node[id].sq)return;
    int l=node[id].l; int r=node[id].r;
    if(l==r){
        node[id].v = (long long)sqrt(node[id].v);
        if(node[id].v<=1)node[id].sq=1;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=y)Update(id<<1, x, y);      //���
    else if(mid<x)Update((id<<1)+1, x, y);  //�ұ�
    else{       //����
        Update(id<<1, x, mid);
        Update((id<<1)+1, mid+1, y);
    }
    node[id].v = node[id<<1].v + node[(id<<1)+1].v;
    node[id].sq = node[id<<1].sq&&node[(id<<1)+1].sq;
}


int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%d", &res[i]);
    BuildTree(1, 1, n);
    scanf("%d", &m);
    while(m--){
        scanf("%d%d%d", &x, &l, &r);
        if(x==1){
            ans=0;
            Query(1, l, r);
            printf("%lld\n", ans);
        }
        else if(x==2){
            Update(1, l, r);
        }
    }
    return 0;
}
