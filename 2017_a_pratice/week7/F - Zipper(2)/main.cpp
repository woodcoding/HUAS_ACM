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
        scanf("%s%s%s", s1+1, s2+1, s3+1);
        s1[0]=s2[0]=s3[0]='0';
        len1=strlen(s1)-1;len2=strlen(s2)-1;len3=strlen(s3)-1;
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=len1;i++){if(s1[i]==s3[i])dp[i][0]=1;}
        for(int j=1;j<=len2;j++){if(s2[j]==s3[j])dp[0][j]=1;}
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                dp[i][j]=((dp[i-1][j]&&s1[i]==s3[i+j])||(dp[i][j-1]&&s2[j]==s3[i+j]));
            }
        }
        printf("Data set %d: %s\n", cas, dp[len1][len2]?"yes":"no");
    }
    return 0;
}
