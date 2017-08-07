#include <iostream>
#include <cstdio>
using namespace std;

int t, n, x;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int c1=0, c2=0;
        while(n--){
            scanf("%d", &x);
            if(x&1)c1++;
            else c2++;
        }
        printf("%s\n", c1>=c2?"2 1":"2 0");
    }
    return 0;
}
