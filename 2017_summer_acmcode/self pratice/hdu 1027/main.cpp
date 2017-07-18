#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int num[maxn], n, m;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<n;i++)num[i]=i+1;
        m-=1;
        while(m--)next_permutation(num, num+n);
        for(int i=0;i<n;i++){
            printf("%d", num[i]);
            putchar(i==n-1?'\n':' ');
        }
    }
    return 0;
}
