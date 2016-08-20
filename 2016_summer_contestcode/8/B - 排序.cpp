#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=1000+10;
char str[maxn];
int ans[maxn];
int cnt=0;

stack<int> num;

void Split()
{
    int len=strlen(str);
    int t, ad, tans;
    cnt=0;
    for(int i=0;i<len;i++)
    {
        t=str[i]-'0';
        if(t!=5){num.push(t);}
        if(t==5 && str[i-1]!='5')
        {
            if(i==0)continue;
            ad=1,tans=0;
            while(!num.empty())
            {
                tans+=num.top()*ad;
                num.pop();
                ad*=10;
            }
            ans[cnt++]=tans;
        }
    }
    if(str[len-1]!='5')
    {
        ad=1,tans=0;
        while(!num.empty())
        {
            tans+=num.top()*ad;
            num.pop();
            ad*=10;
        }
        ans[cnt++]=tans;
    }
}

int main()
{
    while(~scanf("%s", &str))
    {
        Split();
        sort(ans, ans+cnt);
        for(int i=0;i<cnt;i++)
        {
            if(i!=0)printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
