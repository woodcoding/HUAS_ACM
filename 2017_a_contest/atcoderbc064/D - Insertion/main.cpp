#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char s[1000];
int n, a, b, sub;

int main()
{
    while(~scanf("%d%s", &n, &s)){
        a=b=sub=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')a++;
            else if(a)a--;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')b++;
            else if(b)b--;
        }
        for(int i=0;i<b;i++)putchar('(');
        printf("%s", s);
        for(int i=0;i<a;i++)putchar(')');
        printf("\n");
    }
    return 0;
}
