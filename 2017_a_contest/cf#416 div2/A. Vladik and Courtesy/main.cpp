#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int m, n;
    while(~scanf("%d%d", &m, &n)){
        int cm=sqrt(m);
        int tn=cm*cm+cm;
        if(tn>n)printf("Valera\n");
        else printf("Vladik\n");
    }
    return 0;
}
