#include <iostream>
#include <cstdio>
#include <stack>
#include <memory.h>
using namespace std;

const int maxn=1000+5;
char ch1[maxn], ch2[maxn], cht[2];
int n, num1, num2, i;
stack<int> ans;

void Init()
{
    num1=num2=0;
    bool flag=false;
    for(i=0;i<maxn;i++)ch1[i]=ch2[i]='0';
    while(scanf("%c", &cht))
    {
        if(cht[0]=='\n')break;
        if(cht[0]==' '){flag=true;continue;}
        if(!flag)ch1[num1++]=cht[0];
        if(flag)ch2[num2++]=cht[0];
    }
}
void Cal()
{
    while(!ans.empty())ans.pop();
    int tmax=num1>num2?num1:num2;
    int a, b, t=0, res=0;
    for(i=0;i<tmax;i++)
    {
        if(num1-1-i>=0)a=(int)ch1[num1-1-i]-'0';
        else a=0;
        if(num2-1-i>=0)b=(int)ch2[num2-1-i]-'0';
        else b=0;
        res=a+b+t;
        if(res<10)
        {
            ans.push(res);
            t=0;
        }
        else
        {
            t=1;
            res%=10;
            ans.push(res);
            if(i==tmax-1)ans.push(t);
        }
    }
}
void Print()
{
    for(i=0;i<num1;i++)printf("%c", ch1[i]);
    printf(" + ");
    for(i=0;i<num2;i++)printf("%c", ch2[i]);
    printf(" = ");
    while(!ans.empty())
    {
        printf("%d", ans.top());
        ans.pop();
    }
    printf("\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        Init();
        Cal();
        printf("Case %d:\n", i);
        Print();
        if(i!=n)printf("\n");
    }
    return 0;
}
