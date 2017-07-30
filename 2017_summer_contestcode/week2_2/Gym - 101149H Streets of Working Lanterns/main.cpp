#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=500005;
char s[maxn];

int main()
{
    while(~scanf("%s", &s)){
        int len=strlen(s);
        int num=0, g=0, ans=1;
        for(int i=0;i<len;i++){
            if(s[i]=='?')g++;
            else if(s[i]=='(')num++;
            else num--;
        }
        if(abs(num)>g||int(g-abs(num))%2){
            ans=0;
        }
        else{
            int bu=(g-num)/2;
            num=0;
            for(int i=0;i<len;i++){
                if(s[i]=='?'){
                    if(bu){
                        s[i]='(';
                        bu--;
                    }
                    else s[i]=')';
                }
                if(s[i]=='(')num++;
                else num--;
                if(num<0){
                    ans=0;
                    break;
                }
            }
        }
        if(ans){
            printf("%s\n", s);
        }
        else printf("Impossible\n");
    }
    return 0;
}
