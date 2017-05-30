#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=10005;
int data[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)scanf("%d", &data[i]);
    int l, r, x, v;
    while(m--){
        scanf("%d%d%d", &l, &r, &x);
        v = data[x];
        int cl=0;
        for(int i=l;i<=r;i++){
            if(data[i]<v)cl++;
        }
        if(l+cl==x)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
