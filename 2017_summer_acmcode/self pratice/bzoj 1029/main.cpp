#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=150005;
int n;
long long T;

struct node{
    long long t1, t2;
    bool operator<(const node &cmp) const{
        return t1<cmp.t1;
    }
}build[maxn];

bool cmp(node c1, node c2){
    return c1.t2<c2.t2;
}

priority_queue<node> solve;

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld", &build[i].t1, &build[i].t2);
    }
    sort(build, build+n, cmp);
    T=0;
    for(int i=0;i<n;i++){
        if(T+build[i].t1<build[i].t2){
            T+=build[i].t1;
            solve.push(build[i]);
        }
        else if(!solve.empty()){
            if(solve.top().t1>build[i].t1){
                T-=solve.top().t1;
                solve.pop();
                T+=build[i].t1;
                solve.push(build[i]);
            }
        }
    }
    printf("%d\n", solve.size());
    return 0;
}
