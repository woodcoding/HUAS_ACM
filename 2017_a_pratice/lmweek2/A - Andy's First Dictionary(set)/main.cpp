#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> data;
string s, buf;
int main()
{
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]))s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf)data.insert(buf);
    }
    for(set<string>::iterator it=data.begin();it!=data.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}




