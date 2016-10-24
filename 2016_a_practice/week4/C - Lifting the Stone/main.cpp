#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 1000010
#define y0 yy
int n, m;
double x, y, s, t, x0, y0;
struct Node{
    double x, y;
}node[MAX];
double get_area(double x1, double y1, double x2, double y2){
    return (x1*y2-y1*x2)/2;
}
int main()
{
    cin>>n;
    while(n--){
        cin>>m;
        x=y=s=t=0;
        for(int i=0;i<m;i++)cin>>node[i].x>>node[i].y;
        x0 = node[0].x;y0=node[0].y;
        for(int i=1;i<m-1;i++){
            t = get_area(node[i].x-x0, node[i].y-y0, node[i+1].x-x0, node[i+1].y-y0);
            s+=t;
            x+=(node[i].x+node[i+1].x+x0)*t;
            y+=(node[i].y+node[i+1].y+y0)*t;
        }
        printf("%.2lf %.2lf\n", x/(3.0*s), y/(3.0*s));
    }
    return 0;
}