#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

const int maxn=1e6+5;
int n, go[maxn];
char str[maxn];

void getgo(char s[], int num[]){
    int i=1, j=0, len=strlen(s);
    memset(num, 0, sizeof(num));
    while(i<len){
        if(s[i]==s[j]){
            num[i]=j+1;
            i++;j++;
        }
        else{
            if(j==0){num[i]=0;i++;}
            else j=num[j-1];
        }
    }
}

int KMP(char org[], char sub[], int num[]){
    int i=0,j=0,leno=strlen(org), lens=strlen(sub);
    for(int i=0;i<leno;i++){
        if(org[i]==sub[j])j++;
        else j=num[j-1];
        if(j==lens)return i;
    }
    return -1;
}

int getAns(char org[]){
    char s1[maxn], s2[maxn];
    int len=strlen(str), i, j, x, tmp, k;
    i=len/3-1;j=len-1;x=i;
    while(i>=0){
        if(org[i]!=org[j]){i=x-1;j=len-1;x=i;}
        else{i--;j--;}
        if(i==-1){
            i=x+1;
            for(j=0;j<i;j++)s1[j]=org[j];
            for(j=i;j<len-i;j++)s2[j-i]=org[j];
            s1[i]='\0';s2[len-i*2]='\0';
            getgo(s2, go);
            if(KMP(s2, s1, go)>=0)return i;
            if(x==0)break;
            i=x-1;j=len-1;x=i;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%s", &str);
        printf("%d\n", getAns(str));
    }
    return 0;
}
