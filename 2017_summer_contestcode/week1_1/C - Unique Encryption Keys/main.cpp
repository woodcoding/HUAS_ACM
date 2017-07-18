#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int maxn=1000005;
int data[maxn], last[maxn];
int m, q, l, r;
map<int,int> key;

int main()
{
    while(scanf("%d%d", &m, &q)&&m+q){
        key.clear();
        for(int i=1;i<=m;i++)scanf("%d", &data[i]);
        last[m+1]=m+1;
        for(int i=m;i>0;i--){
            last[i]=last[i+1];
            if(key[data[i]])last[i]=min(last[i], key[data[i]]);
            key[data[i]]=i;
        }
        while(q--){
            scanf("%d%d", &l, &r);
            if(last[l]<=r)printf("%d\n", data[last[l]]);
            else printf("OK\n");
        }
        printf("\n");
    }
    return 0;
}
