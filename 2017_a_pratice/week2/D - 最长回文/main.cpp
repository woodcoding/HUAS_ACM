#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 110005

int ans, lenr, lens, mx, id, pd[MAX*2];
char res[MAX*2], str[MAX*2];

void init(){
    lenr=strlen(res);
    str[0]='@';
    str[1]='#';
    for(int i=0;i<lenr;i++){
        str[i*2+2]=res[i];
        str[i*2+3]='#';
    }
    lens=lenr*2+2;
}

void manacher(){
    mx=0;id=0;ans=0;
    for(int i=1;i<lens;i++){
        if(mx>i)pd[i]=min(pd[2*id-i], mx-i);
        else pd[i]=1;
        for(;str[i+pd[i]]==str[i-pd[i]];pd[i]++);
        if(i+pd[i]>mx){
            mx=i+pd[i];id=i;
        }
        ans=max(ans, pd[i]-1);
    }
}

int main()
{
    while(~scanf("%s", res)){
        init();
        manacher();
        printf("%d\n", ans);
    }
    return 0;
}
