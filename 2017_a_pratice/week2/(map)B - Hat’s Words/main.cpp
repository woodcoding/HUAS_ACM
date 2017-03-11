#include <iostream>
#include <map>
#include <cstdio>

using namespace std;
#define MAX 50005
map<string, int> str;

int main()
{
    string res[MAX];
    int cnt=0;
    while(cin>>res[cnt++]){
        str[res[cnt-1]]=1;
    }
    for(int i=0;i<cnt;i++){
        for(int j=1;j<res[i].size();j++){
            string a(res[i], 0, j);
            string b(res[i], j);
            if(str[a]&&str[b]){
                cout<<res[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
