#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1005;
const double L=0, R=1;
const double eps=1e-4;

int a[maxn], b[maxn];
double add[maxn];
int n, k;

bool check(double x){
    for(int i=0;i<n;i++){
        add[i]=a[i]*1.0-x*b[i]*1.0;
    }
    sort(add, add+n);
    double sum=0;
    for(int i=n-1;i>=k;i--)sum+=add[i];
    if(sum>=0)return 1;
    return 0;
}

int main()
{
    while(~scanf("%d%d", &n, &k)&&(n||k)){
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d", &b[i]);
        }
        double l=L, r=R;
        while(r-l>=eps){
            double mid=(l+r)/2;
            if(check(mid))l=mid;
            else r=mid;
        }
        printf("%.0lf\n", 100*l);
    }
    return 0;
}
