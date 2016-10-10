#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 110
using namespace std;

void print(char s[])
{
    int flag=0;
    for(int i=MAX-1; i>-1; i--){
        if(s[i]!='0' || (s[i]=='0' && !i &&!flag))flag=1;   //当sum为0的时候输出0
        if(flag)printf("%c",s[i]);
    }
    cout<<endl;
}

void bigadd(char t[], char sum[])
{
    int t_len=strlen(t);
    for(int i=t_len-1,j=0; i>-1; i--,j++)
    {
        int a=(int)t[i]-'0';
        int b=(int)sum[j]-'0';
        sum[j]='0'+(a+b)%10;
        if((a+b)/10)sum[j+1]+=1;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char sum[MAX], in[MAX];
        for(int i=0;i<MAX;i++)sum[i]='0';
        while(scanf("%s", in))
        {
            if(in[0]=='0')break;
            bigadd(in, sum);
        }
        print(sum);
        if(n)cout<<endl;
    }
    return 0;
}
