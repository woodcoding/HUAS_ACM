#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=505;
const long long inf=0x3f3f3f3f3f3f3f3f;
int data[maxn][maxn];
int sum[maxn][maxn];
int n, m;

int main()
{
    while(~scanf("%d%d", &m, &n)){
        memset(sum, 0, sizeof(sum));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d", &data[i][j]);
                sum[i][j]=sum[i-1][j]+data[i][j];
            }
        }

        LL ans=-inf;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                LL tmp=0;
                for(int k=1;k<=m;k++){
                    LL now=sum[j][k]-sum[i-1][k]+tmp;
                    //cout<<"now:"<<now<<"  "<<i<<"  "<<j<<"  "<<k<<endl;
                    if(now>0){
                        tmp=now;
                        ans=max(ans, tmp);
                    }
                    else{
                        tmp=0;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
