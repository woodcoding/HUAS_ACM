#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=50005;

int n;
LL data[maxn], l[maxn], r[maxn];
stack<LL> L, R;

int main()
{
    while(~scanf("%d", &n)){
        while(!L.empty())L.pop();
        while(!R.empty())R.pop();
        for(int i=1;i<=n;i++)scanf("%lld", &data[i]);
        data[0]=data[n+1]=-1;
        L.push(0);R.push(n+1);
        for(int i=1;i<=n;i++){
            while(L.size()&&data[L.top()]>=data[i])L.pop();
            if(L.size())l[i]=L.top()+1;
            else l[i]=i;
            L.push(i);
        }
        for(int i=n;i>0;i--){
            while(R.size()&&data[R.top()]>=data[i])R.pop();
            if(R.size())r[i]=R.top()-1;
            else r[i]=i;
            R.push(i);
        }
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans, (r[i]-l[i]+1)*data[i]);
            //cout<<l[i]<<"  "<<r[i]<<endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
