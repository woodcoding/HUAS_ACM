#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn= 50005;

int n, m, x, mi[maxn], disk[maxn], ans;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        stack<int> jin;
        mi[0]=inf;
        for(int i=1;i<=n;i++){
            scanf("%d", &x);
            jin.push(x);
            mi[i]=min(mi[i-1], x);
        }
        for(int i=1;i<=m;i++){
            scanf("%d", &disk[i]);
        }
        ans=0;
        for(int i=1;i<=m;i++){
            while(jin.size()&&mi[jin.size()]<disk[i]){
                jin.pop();
            }
            if(jin.size()){
                ans++;
                jin.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
