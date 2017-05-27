#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100005;
int t, n;
int fb[maxn], dp[maxn];

int main()
{
    fb[1]=1;fb[2]=2;dp[0]=1;
    int cnt=3;
    while(fb[cnt-1]+fb[cnt-2]<maxn){
        fb[cnt]=fb[cnt-1]+fb[cnt-2];
        cnt++;
    }
    for(int i=1;i<cnt;i++){
        for(int j=100000;j>=fb[i];j--){
            dp[j]+=dp[j-fb[i]];
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
