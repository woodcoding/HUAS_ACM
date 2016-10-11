#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000
char Dec(char ch){
    if(ch>='F' && ch<='Z')ch-=5;
    else ch+=21;
    return ch;
}

int main()
{
    char text[MAX];
    int len;
    while(1){
        gets(text);
        if(!strcmp(text, "START") || !strcmp(text, "END"))continue;
        else if(!strcmp(text, "ENDOFINPUT"))break;
        else{
            len = strlen(text);
            for(int i=0;i<len;i++){
                if(text[i]>='A'&&text[i]<='Z')text[i]=Dec(text[i]);
            }
            printf("%s\n", text);
        }
    }
    return 0;
}
