#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi=3.141592654;
struct Circle{
    double x, y, r;
}cs1, cs2, cb1, cb2;

int t, r, R, x, y, x2, y2;

double cArea(Circle c1, Circle c2){
    double d=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    if(c1.r+c2.r<=d)return 0;
    double minr=min(c1.r, c2.r), maxr=max(c1.r, c2.r);
    if(maxr-minr>=d)return pi*minr*minr;
    double ang1=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double ang2=acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));
    return c1.r*c1.r*ang1+c2.r*c2.r*ang2-c1.r*sin(ang1)*d;
}

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d%d%d%d", &r,&R,&x,&y,&x2,&y2);
        cs1.r=cs2.r=r;
        cb1.r=cb2.r=R;
        cs1.x=cb1.x=x;
        cs1.y=cb1.y=y;
        cs2.x=cb2.x=x2;
        cs2.y=cb2.y=y2;
        double ans=cArea(cb1, cb2)-2*cArea(cb1, cs2)+cArea(cs1, cs2);
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}
