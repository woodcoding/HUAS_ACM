#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;
#define MAX 10010

int dp[MAX], num[MAX];
int n, len;
char str[MAX];
const long long mod = 1e8+7;

int main()
{
    while(~scanf("%d", &n)){
        while(n--){
            scanf("%s", &str);
            memset(num, 0, sizeof(num));
            memset(dp, 0, sizeof(dp));
            len=strlen(str);
            long long ans=0;
            for(int i=1;i<=len;i++)num[i]=str[i-1]-'0';
            for(int i=0;i<=num[1];i++){
                if(i>2)break;   //��һ�д���2���������
                dp[1]=i;
                int j;
                for(j=2;j<=len;j++){
                    int cnt=num[j-1]-dp[j-1]-dp[j-2];
                    if(cnt>2||cnt<0)break;  //���������
                    dp[j]=cnt;
                }
                if(j<=len)continue;     //��ǰ�����޷�����
                if(dp[len-1]+dp[len]!=num[len])continue;    //��ǰ�����޷�����
                long long sub=1;
                for(int i=1;i<=len;i++){
                    if(dp[i]==1){
                        sub<<=1;        //ֻ��1���׵�ʱ�������ַ���
                        sub%=mod;
                    }
                }
                ans+=sub;
                ans%=mod;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
