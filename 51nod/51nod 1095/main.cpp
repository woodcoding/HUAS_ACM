#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
const int maxn=10000;
char str[20];
const int p=29;
ULL hasht[maxn];
int N, Q;

map<ULL, int> cnt;
map<ULL, bool> exist;

ULL get_hash(char s[]){
    ULL ha=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        ha+=ha*p+s[i]-'a'+1;
    }
    return ha;
}

int main()
{
    while(~scanf("%d", &N)){
        cnt.clear();
        exist.clear();
        for(int i=0;i<N;i++){
            scanf("%s", str);
            exist[get_hash(str)]=1;
            int len=strlen(str);
            sort(str, str+len);
            cnt[get_hash(str)]++;
        }
        scanf("%d", &Q);
        while(Q--){
            scanf("%s", str);
            int ans=exist[get_hash(str)];
            sort(str, str+strlen(str));
            ans=cnt[get_hash(str)]-ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}
