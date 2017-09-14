#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
const int maxn=100005*2;
const int p=163;
int T;
char key[30], str[maxn], str2[maxn], pwd[30];
ULL px[maxn];
ULL hash1[maxn], hash2[maxn];

ULL get(int l, int r, ULL ht[]){
    return ht[r]-ht[l-1]*px[r-l+1];
}

void init(){
    int n=strlen(str+1);
    for(int i=1;i<=n;i++){
        str2[i]=key[str[i]-'a'];
    }
    str2[n+1]=0;
    px[0]=1;
    hash1[0]=hash2[0]=0;
    for(int i=1;i<=n;i++){
        px[i]=px[i-1]*p;
        hash1[i]=hash1[i-1]*p+str[i]-'a'+1;
        hash2[i]=hash2[i-1]*p+str2[i]-'a'+1;
    }
    for(int i=0;i<26;i++){
        pwd[key[i]-'a']=i+'a';
    }
}

void solve(){
    int len=strlen(str+1);
    int slen=len/2, i, j;
    for(i=slen;i>=1;i--){
        ULL h1=get(1, i, hash1);
        ULL h2=get(len-i+1, len, hash2);
        if(h1==h2)break;
    }
    for(j=1;j<=len-i;j++){
        str[j+len-i]=pwd[str[j]-'a'];
    }
    str[j+len-i]=0;
}

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%s%s", key, str+1);
        init();
        solve();
        printf("%s\n", str+1);
    }
    return 0;
}
