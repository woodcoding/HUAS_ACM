#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=20;
char s[maxn];
int cnt, len;

int main()
{
    while(~scanf("%s", &s)){
        len = strlen(s);
        cnt=0;
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-i-1])cnt++;
        }
        printf("%s\n", (cnt==1||(len%2&&!cnt))?"YES":"NO");
    }
    return 0;
}
