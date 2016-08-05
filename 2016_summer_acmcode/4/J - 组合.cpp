#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a>b){int x=a;a=b;b=x;}
        int t=b-a;
        int p=t*(1.0+sqrt(5.0))/2.0;
        if(p==a)printf("0\n");  //奇异局势
        else printf("1\n");     //非奇异局势
    }
    return 0;
}
