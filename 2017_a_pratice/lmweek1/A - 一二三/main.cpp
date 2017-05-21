#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=15;
int t, ans;
char str[maxn];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%s", &str);
        if(strlen(str)==5)ans=3;
        else{
            ans=1;
            if(str[1]=='w'&&str[2]=='o'||(str[0]=='t'&&(str[1]=='w'||str[2]=='o')))ans=2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
