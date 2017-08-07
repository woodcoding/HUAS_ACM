#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=105;
char s[maxn];
int main()
{
    while(~scanf("%s", s)){
        int len=strlen(s);
        printf("%c%d%c\n", s[0], len-2, s[len-1]);
    }
    return 0;
}
