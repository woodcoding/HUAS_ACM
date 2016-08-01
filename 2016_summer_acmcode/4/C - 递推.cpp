#include <iostream>
#include <cstdio>
using namespace std;

int x, n, m;

int main()
{
    scanf("%d", &x);
    while(x--)
    {
        scanf("%d%d", &n,&m);
        printf("%d\n", (1+n)*n/2*(1+m)*m/2);	//横的乘以竖的
    }
    return 0;
}
