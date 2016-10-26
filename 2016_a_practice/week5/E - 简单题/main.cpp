#include <iostream>

using namespace std;

#define LL long long

const LL mod = 100003;

int mmod(LL x, LL y)
{
    LL val=1;
    while(y){
        if(y%2)val = (val*x)%mod;
        x = (x*x)%mod;
        y/=2;
    }
    return val;
}

int main()
{
    LL m, n, ans;
    while(cin>>m>>n)
    {
        LL ans1=mmod(m, n);
        LL ans2=mmod(m-1, n-1);
        ans=(ans1-m*ans2)%mod;
        if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
