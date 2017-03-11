#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>
using namespace std;

#define MAX 27
#define STRMAX 50005

struct Dict{
    bool is;
    Dict *next[MAX];
    Dict(){
        is=0;
        for(int i=0;i<MAX;i++)next[i]=NULL;
    }
};

void Insert_item(Dict *p, string str){
    Dict *now = p;
    for(int i=0;i<str.size();i++){
        int x=str[i]-'a';
        if(now->next[x]==NULL)now->next[x]=new Dict;
        now = now->next[x];
    }
    now->is=1;
}

bool search_item(Dict *p, string str){
    Dict *now = p;
    for(int i=0;i<str.size();i++){
        int x=str[i]-'a';
        if(now==NULL||now->next[x]==NULL)return 0;
        now = now->next[x];
    }
    return now->is;
}

int main()
{
    string str[STRMAX];
    int pos=0;
    Dict *node = new Dict;
    while(cin>>str[pos]){
        Insert_item(node, str[pos++]);
    }
    for(int i=0;i<pos;i++){
        for(int j=1;j<str[i].size();j++){
            string a(str[i], 0, j);
            string b(str[i], j);
            if(search_item(node, a)&&search_item(node, b)){
                cout<<str[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
