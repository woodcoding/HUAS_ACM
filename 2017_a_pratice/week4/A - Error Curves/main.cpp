#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAX 10005

int func[MAX][3];
int n, t;
double ans;

double cal(double x){
    double maxx=-1e9, tmp, a, b, c;
    for(int i=0;i<n;i++){
        a=func[i][0];
        b=func[i][1];
        c=func[i][2];
        tmp=a*x*x+b*x+c;
        if(tmp>maxx)maxx=tmp;
    }
    return maxx;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &func[i][0], &func[i][1], &func[i][2]);
        }
        double l=0,r=1000;
        while(r-l>1e-9){
            double mid=(l+r)/2;
            double mmid=(mid+r)/2;
            if(cal(mid)>cal(mmid)){
                l=mid;
            }
            else{
                r=mmid;
            }
        }
        printf("%.4lf\n", cal(l));
    }
    return 0;
}
