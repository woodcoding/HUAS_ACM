#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxl=205;
const int maxn=5005;
char str[maxl], c;

struct Data{
    char word[maxl];

    bool operator< (const Data & cmp) const {
        return strcmp(word, cmp.word)<0;
    }
}data[maxn*maxl];

int main()
{
    int cnt=0, pos=0;
    while(~(c=getchar())){
        if(isalpha(c))str[pos++]=tolower(c);
        else if(pos){
            str[pos]=0;
            strcpy(data[cnt++].word, str);
            pos=0;
        }
    }
    sort(data, data+cnt);
    for(int i=0;i<cnt;i++){
        if(!i||strcmp(data[i].word, data[i-1].word)!=0)printf("%s\n", data[i].word);
    }
    return 0;
}
