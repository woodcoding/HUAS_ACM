#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100005;
int data[maxn], len[maxn], f[maxn], ans[maxn];
int cas, n, cnt;

int low_bound(int x){
    int l=1, r=cnt, mid;
    while(l<r){
        mid=(l+r)/2;
        if(f[mid]>=x)r=mid;
        else l=mid+1;
    }
    return l;
}

void solve(){
    cnt=1;
    len[cnt]=1;
    f[cnt]=data[1];
    for(int i=2;i<=n;i++){
        if(data[i]>f[cnt]){
            f[++cnt]=data[i];
            len[i]=cnt;
        }
        else{
            int t=low_bound(data[i]);
            f[t]=data[i];
            len[i]=t;
        }
    }
    int now=cnt, last=maxn;
    for(int i=n;i>0;i--){
        if(len[i]==now&&data[i]<last){
            ans[now--]=last=data[i];
        }
    }
}

int main()
{
    scanf("%d", &cas);
    while(cas--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)scanf("%d", &data[i]);
        solve();
        printf("%d\n", cnt);
        for(int i=1;i<=cnt;i++){
            printf("%d", ans[i]);
            putchar(i==cnt?'\n':' ');
        }
    }
    return 0;
}
