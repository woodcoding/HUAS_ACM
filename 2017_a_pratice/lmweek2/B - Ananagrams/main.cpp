#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<string, int> data;
vector<pair<string, string> > res;
set<string> ans;
string str, tmp;

int main()
{
    while(cin>>str&&str!="#"){
        tmp = str;
        for(int i=0;i<tmp.size();i++)tmp[i]=tolower(tmp[i]);
        sort(tmp.begin(), tmp.end());
        data[tmp]++;
        res.push_back(make_pair(tmp, str));
    }
    for(vector<pair<string, string> >::iterator it=res.begin();it!=res.end();it++){
        if(data[it->first]==1)ans.insert(it->second);
    }
    for(set<string>::iterator it=ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
