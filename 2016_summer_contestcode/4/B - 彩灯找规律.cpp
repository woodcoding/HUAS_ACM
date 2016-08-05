#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=31;
int res[maxn], m;
long long n;

void solve()
{
    for(int i=1;i<=30;i++)res[i]=0;
    for(int i=1;i<=m;i++)
    {
        res[i]=n%3;
        n/=3;
    }
}

void print()
{
    for(int i=m; i>=1;i--)
    {
        switch(res[i])
        {
        case 1:
            printf("G");
            break;
        case 2:
            printf("B");
            break;
        case 0:
            printf("R");
            break;
        }
    }
    printf("\n");
}

int main()
{
    int x;
    scanf("%d", &x);
    while(x--)
    {
        scanf("%d%lld", &m, &n);
        solve();
        print();
    }
    return 0;
}
