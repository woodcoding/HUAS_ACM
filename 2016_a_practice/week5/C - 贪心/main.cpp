#include <iostream>
#include <cmath>
using namespace std;

struct One{int len, e;};

One get_one(int x){
    int len=0;
    One one;
    while(x%10==0)x/=10;
    one.e=x%10;
    while(x){
        len++;
        x/=10;
    }
    one.len=len;
    return one;
}

int intlen(int x){
    int len=0;
    while(x){
        len++;
        x/=10;
    }
    return len;
}

int main()
{
    int t, l, r, p, tans, ans;
    cin>>t;
    while(t--){
        cin>>l>>r;
        tans = ans = l;
        One one = get_one(l);
        p=2*one.len;
        if(one.e==5)p-=1;
        //Ì°ÐÄ0ºÍ5
        int tlen, tp, jc=0;
        while(tans<=r){
            tans+=pow(10, jc);
            if(tans>r)break;
            one = get_one(tans);
            tp = 2*one.len;
            if(one.e==5)tp-=1;
            if(tp<p){p=tp;ans=tans;}
            jc = intlen(tans)-one.len;
            if(one.e==5 && one.len==1)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
