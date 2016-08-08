#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int dp[maxn][maxn], len1, len2, i, j;
char str1[maxn], str2[maxn];

int main()
{
    while(~scanf("%s %s", &str1, &str2))
    {
        len1=strlen(str1);
        len2=strlen(str2);
        for(i=0;i<maxn;i++)dp[0][i]=dp[i][0]=0; //初始化边界为0
        for(i=1;i<=len1;i++)
            for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;   //如果当前两个字符相同则公共字符串可以加1
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}
