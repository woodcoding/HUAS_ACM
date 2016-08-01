#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=20;
long long num[maxn];
int n;
int main()
{
    num[0]=0;
    num[1]=1;
    for(int i=2;i<20;i++)num[i]=i*(num[i-1]+num[i-2]);		//递推
    while(scanf("%d", &n)!=EOF)
    {
        printf("%lld\n", num[n-1]);
    }
    return 0;
}
