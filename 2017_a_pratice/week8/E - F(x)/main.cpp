#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

const int maxl=10;
const int maxn=20000;

int n, a, b, cnt, cas=1;
int num[maxl], dp[maxl][maxn];

int dfs(int len, int q, bool flag){
    if(len==-1)return q>=0;         //返回最后一位的满足个数
    if(q<0)return 0;
    if(!flag&&dp[len][q]!=-1)return dp[len][q];     //如果当前长度已经dp并且不是边界则直接返回即可
    int ed=flag?num[len]:9;                         //如果是边界长度则取边界值
    int ans=0;
    for(int i=0;i<=ed;i++){
        ans+=dfs(len-1, q-i*(1<<len), flag&&i==ed); //搜索下一位满足条件和
    }
    if(!flag)dp[len][q]=ans;
    return ans;
}

int q(int x){
    int tmp=0, cnt=0;
    while(x){
        tmp+=(x%10)*(1<<cnt++);
        x/=10;
    }
    return tmp;
}

int main()
{
    int i=0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &a, &b);
        cnt=0;
        while(b){
            num[cnt++]=b%10;
            b/=10;
        }
        printf("Case #%d: %d\n", cas++, dfs(cnt-1, q(a), 1));
    }
    return 0;
}
