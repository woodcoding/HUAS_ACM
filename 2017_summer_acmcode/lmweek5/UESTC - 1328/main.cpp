#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100005;
int f[maxn*2];       //f[i]∫√»À£¨f[i+1]ªµ»À
int n, a, t;

int Find(int x){
    return f[x]==x?x:f[x]=Find(f[x]);
}

void Union(int x, int y){
    int fx=Find(x), fy=Find(y);
    if(fx!=fy)f[x]=f[y];
    return;
}

int main()
{
    while(~scanf("%d", &n)){
        for(int i=1;i<=n*2;i++){
            f[i]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d%d", &a, &t);
            if(t==1){
                Union(i, a);
                Union(i+n, a+n);
            }
            else{
                Union(i, a+n);
                Union(i+n, a);
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            if(f[i]==f[i+n])ans=0;
        }
        if(ans)puts("Time to show my power");
        else puts("One face meng bi");
    }
    return 0;
}
