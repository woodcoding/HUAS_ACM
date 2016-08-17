#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int x, len, z1, z2, z3;
char str[10];

int main()
{
    while(~scanf("%d", &x) && x)
    {
        while(x--)
        {
            scanf("%s", &str);
            len = strlen(str);
            if(len==5)printf("3\n");
            else
            {
                z1 = str[0]=='o'?1:0;
                z2 = str[1]=='n'?1:0;
                z3 = str[2]=='e'?1:0;
                if((z1+z2+z3)>=2)printf("1\n");
                else printf("2\n");
            }
        }
    }
    return 0;
}
