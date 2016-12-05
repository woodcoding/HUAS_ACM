#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double p, q, pmin1,qmax1;
    int pmin, qmax, flag;
    while(~scanf("%lf %lf", &p, &q)){
        int ans=1;
        p/=100.0;
        q/=100.0;
        while(1){
            pmin1=ans*p;
            qmax1=ans*q;
            pmin=int(pmin1);
            qmax=int(qmax1);
            if(qmax>pmin&&pmin1-pmin>0.0001&&qmax1-qmax>0.0001)break;
            ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
