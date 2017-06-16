#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int r, g, b;
    while(~scanf("%d%d%d", &r, &g, &b)){
        printf("%s\n", (r*100+g*10+b)%4?"NO":"YES");
    }
    return 0;
}
