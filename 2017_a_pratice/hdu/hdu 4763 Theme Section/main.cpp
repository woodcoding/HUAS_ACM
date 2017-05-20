#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <vector>
using namespace std;

const int maxn=1e6+5;
int fail[maxn];
char s1[maxn], s2[maxn], str[maxn];;
int n;

void getFail(char *P, int *f){
    int lenP=strlen(P);
    f[0]=0;f[1]=0;
    for(int i=1;i<lenP;i++){
        int j=f[i];
        while(j&&P[i]!=P[j])j=f[j];
        f[i+1]=(P[i]==P[j]?j+1:0);
    }
}

vector<int> KMP(char *T, char *P, int *f){
    int lenT=strlen(T), lenP=strlen(P), j=0;
    getFail(P, f);
    vector<int> ans;
    for(int i=0;i<lenT;i++){
        while(j&&P[j]!=T[i])j=f[j];
        if(P[j]==T[i])j++;
        if(j==lenP)ans.push_back(i-lenP+1);
    }
    return ans;
}

int getAns(char org[]){
    int len=strlen(org), i, j, x, tmp, k;
    i=len/3-1;j=len-1;x=i;
    if(i<0)return 0;
    while(i>=0){
        if(org[i]!=org[j]){i=x-1;j=len-1;x=i;}
        else{i--;j--;}
        if(i==-1){
            i=x+1;
            for(j=0;j<i;j++)s1[j]=org[j];
            for(j=i;j<len-i;j++)s2[j-i]=org[j];
            s1[i]='\0';s2[len-i*2]='\0';
            vector<int> ans=KMP(s2, s1, fail);
            if(ans.size()>0)return i;
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
