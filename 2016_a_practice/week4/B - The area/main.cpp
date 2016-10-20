#include <iostream>
#include <cstdio>
using namespace std;

double a, b, c, ans;
double x1,x2,x3,y1,y2,y3;
int n;

double integ(double x){
    return a*(x*x*x/3.0-x1*x*x+x1*x1*x)+y1*x-b*x*x/2.0-c*x;
}

int main()
{
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        a = (y2-y1)/((x2-x1)*(x2-x1));
        b = (y3-y2)/(x3-x2);
        c = (x3*y2-x2*y3)/(x3-x2);
        ans = integ(x3)-integ(x2);
        printf("%.2lf\n", ans);
    }
    return 0;
}
