#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class Point
{
public:
    double x;
    double y;
    Point(double px, double py):x(px),y(py){}
    void Rotate(double rad);
    void Print();
};
void Point::Rotate(double rad)
{
    ///坐标旋转函数
    double tx,ty;
    tx=x*cos(rad)-y*sin(rad);
    ty=x*sin(rad)+y*cos(rad);
    x=tx;
    y=ty;
}
void Point::Print()
{
    printf("%.3lf %.3lf", x, y);
}

const double PI=3.141592654;

int main()
{
    int n;
    double x,y;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        Point point1(x,y);
        Point point2(x,y);
        point1.Rotate(2*PI/3);
        point2.Rotate(-2*PI/3);
        //判断两个点的大小
        int maxPoint=(point1.y<point2.y || point1.y==point2.y && point1.x<point2.x)?1:2;
        if(maxPoint==1)
        {
            point1.Print();
            cout<<" ";
            point2.Print();
            cout<<endl;
        }
        if(maxPoint==2)
        {
            point2.Print();
            cout<<" ";
            point1.Print();
            cout<<endl;
        }
    }
    return 0;
}
