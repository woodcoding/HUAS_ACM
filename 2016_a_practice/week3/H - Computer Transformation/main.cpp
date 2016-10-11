#include <iostream>
#include <algorithm>
#define MAX 1010
using namespace std;

string sum(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    int i,j;
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
    {
        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
        if(s1[i]-'0'>=10)
        {
            s1[i]=char((s1[i]-'0')%10+'0');
            if(i) s1[i-1]++;
            else s1='1'+s1;
        }
    }
    return s1;
}

string Multiply(string s,int x)  //大数乘以整形数
{
    reverse(s.begin(),s.end());
    int cmp=0;
    for(int i=0;i<s.size();i++)
    {
        cmp=(s[i]-'0')*x+cmp;
        s[i]=(cmp%10+'0');
        cmp/=10;
    }
    while(cmp)
    {
        s+=(cmp%10+'0');
        cmp/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    int n;
    string num[MAX],ans[MAX];
    num[1]='1';
    for(int i=2;i<MAX;i++)num[i]=Multiply(num[i-1], 2);
    ans[1]='0';ans[2]='1';
    for(int i=3;i<MAX;i++)ans[i]=sum(num[i-2], ans[i-2]);
    while(cin>>n){
        cout<<ans[n]<<endl;
    }
    return 0;
}
