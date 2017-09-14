#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

string Manacher(string s){
    string t="@#";
    for(int i=0;i<s.size();i++){
        t+=s[i];t+="#";
    }
    vector<int> p(t.size(), 0);
    int mx=0,id=0,slen=0,smid=0;
    for(int i=1;i<t.size();i++){
        p[i]=mx>i?min(p[2*id-i], mx-i):1;
        while(t[i+p[i]]==t[i-p[i]])++p[i];
        if(mx<i+p[i]){
            mx=i+p[i];id=i;
        }
        if(slen<p[i]){
            slen=p[i];smid=i;
        }
    }
    return s.substr((smid-slen)/2, slen-1);
}

int main()
{
    string s;
    while(cin>>s){
        string ans=Manacher(s);
        printf("%d\n", ans.length());
    }
    return 0;
}
