#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn=205;

int dp[maxn][maxn], n, len1,len2,len3;
char s1[maxn], s2[maxn], s3[maxn];

int main()
{
    scanf("%d", &n);
    for(int cas=1;cas<=n;cas++){
        scanf("%s%s%s", &s1[1], &s2[1], &s3[1]);
        s1[0]=s2[0]=s3[0]='0';
        len1=strlen(s1)-1;len2=strlen(s2)-1;len3=strlen(s3)-1;
        memset(dp, -1, sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(dp[i][j]!=-1){
                    if(s2[j+1]==s3[dp[i][j]+1]){
                        dp[i][j+1]=dp[i][j]+1;
                    }
                    if(s1[i+1]==s3[dp[i][j]+1]){
                        dp[i+1][j]=dp[i][j]+1;
                    }
                }
            }
        }
        if(dp[len1][len2]==len3){
            printf("Data set %d: yes\n", cas);
        }
        else printf("Data set %d: no\n", cas);
    }
    return 0;
}
