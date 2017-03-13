#include <iostream>
#include <cstdio>
using namespace std;

const int pi=23,ei=28,ii=33, days=21252;
int p, e, i, d, ans;

int main()
{
    int cas=1;
    while(~scanf("%d%d%d%d", &p,&e,&i,&d)&&p+e+i+d!=-4){
        if(p>=pi)p%=pi;
        if(e>=ei)e%=ei;
        if(i>=ii)i%=ii;
        ans=0;
        for(int j=0;;j++){
            ans=j*ii+i;
            if(ans%pi==p&&ans%ei==e)break;
        }
        if(ans<=d)ans+=days;
        if(ans>d)ans-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n", cas++, ans);
    }
    return 0;
}
