#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=500005;
int n, m;
int dp[maxn], sum[maxn], que[maxn];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int getDp(int i, int j){
    return dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
}

int getUp(int j, int k){
    return dp[j]+sum[j]*sum[j]-dp[k]-sum[k]*sum[k];
}

int getDown(int j, int k){
    return 2*(sum[j]-sum[k]);
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        sum[0]=dp[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=read();
            sum[i]+=sum[i-1];
        }
        int head=0, tail=0;
        que[tail++]=0;
        for(int i=1;i<=n;i++){
            while(head+1<tail && getUp(que[head+1], que[head])<=sum[i]*getDown(que[head+1], que[head]))
                head++;     //找到最优解
            dp[i]=getDp(i, que[head]);
            while(head+1<tail && getUp(i, que[tail-1])*getDown(que[tail-1], que[tail-2])<=getDown(i, que[tail-1])*getUp(que[tail-1], que[tail-2]))
                tail--;     //删除斜率变小的点
            que[tail++]=i;  //当前点放入队列
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
