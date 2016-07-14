#include <iostream>
#include <cstring>
#include <memory.h>

using namespace std;
const int maxn=100000+10;
char str[maxn];
int flag[maxn];
int len;

int main()
{
    while(cin>>str)
    {
        memset(flag, -10, sizeof(flag));
        len=strlen(str);
        int cur = -10;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='['){flag[i]=i;cur=-1;}
            else if(str[i]==']'){flag[i]=i;cur=-2;}
            else
            {
                flag[i]=cur;
            }
        }
        const int xb=-1;
        int xbi=0;
        int xflag=0;
        for(int x=len-1;x>=0;x--)
        {
            if(xb==flag[x]&&!xflag)
            {
                xbi=x;
                xflag=1;
            }
            if(xflag&&flag[x]!=xb)
            {
                for(int cx=x+1;cx<=xbi;cx++){cout<<str[cx];}
                xflag=0;
            }
        }
        for(int x=0;x<len;x++)
        {
            if(flag[x]==-10)cout<<str[x];
        }
        for(int x=0;x<len;x++)
        {
            if(flag[x]==-2)cout<<str[x];
        }
        cout<<endl;
    }
    return 0;
}
