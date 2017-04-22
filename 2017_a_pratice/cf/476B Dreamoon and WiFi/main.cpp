#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=20;
char s1[maxn], s2[maxn];

int main()
{
    scanf("%s%s", &s1, &s2);
    int x=0, y=0, z=0;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='+')x++;
        else y++;
        if(s2[i]=='+')x--;
        else if(s2[i]=='-')y--;
        else z++;
    }
    long long n=0, m=pow(2, z);
    if(x>=0&&y>=0){
        n=1;        //c(z, x);
        for(int i=0;i<x;i++)n*=(z-i);
        for(int i=2;i<=x;i++)n/=i;
    }
    printf("%.10lf\n", 1.0*n/m);
    return 0;
}
