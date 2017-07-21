#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
#define PAIR pair<int, int>
const int maxn=100005;
int a[maxn], b[maxn];
priority_queue<PAIR, vector<PAIR>, greater<PAIR> > ans;
int n;

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]);
    sort(a, a+n);sort(b,b+n);
    for(int i=0;i<n;i++)
        ans.push(make_pair(a[i]+b[0], 0));
    for(int i=0;i<n;i++){
        int v=ans.top().first, p=ans.top().second;
        printf("%d\n", v);
        ans.pop();
        if(p+1<n)ans.push(make_pair(v-b[p]+b[p+1], p+1));
    }
    return 0;
}
