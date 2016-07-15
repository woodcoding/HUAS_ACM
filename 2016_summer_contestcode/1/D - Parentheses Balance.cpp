#include <iostream>
#include <stack>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn=128+10;
stack<char> mystr;

int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        char str[maxn];
        while(!mystr.empty())mystr.pop();
        cin.getline(str, maxn, '\n');
        int len=strlen(str);
        if(!len){cout<<"Yes"<<endl;continue;}
        mystr.push(str[0]);
        for(int i=1;i<len;i++)
        {
            char tchar;
            if(str[i]==')')tchar='(';
            else if(str[i]==']')tchar='[';
            else tchar='gg';
            if(!mystr.empty()&&mystr.top()==tchar)
            {
                mystr.pop();
                //cout<<"Åä¶Ô:"<<tchar<<endl;
            }
            else mystr.push(str[i]);

        }
        if(mystr.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
