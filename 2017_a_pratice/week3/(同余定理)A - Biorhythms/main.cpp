#include <iostream>
#include <cstdio>
using namespace std;

const int pi=23,ei=28,ii=33,days=21252;
int p, e, i, d;
const int a=6,b=19,c=2;

int main()
{
    int cas=1;
    while(~scanf("%d%d%d%d", &p,&e,&i,&d)&&p+e+i+d!=-4){
        int ans=(ei*ii*a*p + pi*ii*b*e + pi*ei*c*i)% days;
        if(ans<=d)ans+=days;
        if(ans>d)ans-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n", cas++, ans);
    }
    return 0;
}
