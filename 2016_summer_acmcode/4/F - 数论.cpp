#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m, n, x;
    scanf("%d", &x);
    while(x--)
    {
        scanf("%d%d", &m, &n);
        if(m==1||n==1)printf("NO\n");			//判断两种特殊情况就好
        else if(m%2==0&&n%2==0)printf("YES\n");
        else if(m%n==0||n%m==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
