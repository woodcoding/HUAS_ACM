#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=1e5+5;
const int inf = 0x3f3f3f3f;

struct RES{
    int x, pos, pre, next;
    bool operator<(const RES &cmp) const{
        return x<cmp.x;
    }
}res[maxn];

int n, ans, idx[maxn];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            res[i].x=read();
            res[i].pos=i;
        }
        sort(res+1, res+n+1);
        res[0].x=-inf;res[0].pos=0;
        res[n+1].x=inf;res[n+1].pos=n+1;
        for(int i=1;i<=n;i++){
            res[i].pre=i-1;
            res[i].next=i+1;
            idx[res[i].pos]=i;      //记录排序后的原始序号
        }
        ans=0;
        for(int i=1;i<n;i++){
            int pos=idx[i];
            int t1=abs(res[pos].x-res[res[pos].pre].x);
            int t2=abs(res[pos].x-res[res[pos].next].x);
            ans+=min(t1, t2);
            res[res[pos].pre].next=res[pos].next;   //当前的上一个数据的next链接到当前的下一个
            res[res[pos].next].pre=res[pos].pre;    //当前的下一个数据的pre链接到当前的上一个，相当于删除节点操作
        }
        ans+=res[idx[n]].x;
        printf("%d\n", ans);
    }
    return 0;
}
