#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        printf("%d\n", 2+3*x*(x-1));	//画三个三角形总结一下
    }
    return 0;
}
