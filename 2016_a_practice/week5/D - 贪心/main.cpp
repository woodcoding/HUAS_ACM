#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX 200005

struct Tree{
    int l,r,v,go,no;
}tree[MAX<<1];      //开两倍用于存储变化过的树

struct cmp{     ///最大值优先
    bool operator()(Tree &a, Tree &b){
        return a.v<b.v;
    }
};
priority_queue<Tree, vector<Tree>, cmp>Q;
bool vis[MAX<<1]={0};

int Good(int num, int m){
    int ans=0, l, r;
    memset(vis, 0, sizeof(vis));
    for(int i=1;i<=m;i++){
        Tree one = Q.top();
        Q.pop();
        if(vis[one.no]){i--;continue;}
        ans+=one.v;
        vis[one.no]=1;
        l = one.l;
        r = one.r;
        while(tree[l].go)l=tree[l].go;       //最左边
        while(tree[r].go)r=tree[r].go;       //最右边
        num++;      //转化一颗新的树
        tree[num].no = num;
        tree[num].go = 0;
        tree[num].v = tree[l].v+tree[r].v-one.v;
        tree[num].l = tree[l].l;
        tree[num].r = tree[r].r;
        tree[l].go = num;
        tree[r].go = num;
        vis[l]=vis[r]=1;
        Q.push(tree[num]);
    }
    return ans;
}

int main()
{
    int n, m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>tree[i].v;
            tree[i].l = i-1;
            tree[i].r = i+1;
            tree[i].no = i;
            tree[i].go = 0;
        }
        tree[1].l = n;      //处理边缘值
        tree[n].r = 1;
        if(m*2>n){cout<<"Error!"<<endl;continue;}
        while(!Q.empty())Q.pop();   //清空队列
        for(int i=1;i<=n;i++)Q.push(tree[i]);       //进入优先队列
        cout<<Good(n,m)<<endl;
    }
    return 0;
}
