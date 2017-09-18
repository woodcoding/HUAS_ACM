#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;
const int maxn=305;
int n, data[maxn][maxn];

int main()
{
    while(~scanf("%d", &n)){
        LL ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &data[i][j]);
                ans+=data[i][j];
            }
        }
        ans/=2;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(data[i][j]>data[i][k]+data[k][j]){
                        ans=-1;break;
                    }
                }
            }
        }
        if(ans!=-1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=0;k<n;k++){
                        if(i==k||j==k)continue;
                        if(data[i][j]==data[i][k]+data[k][j]){
                            ans-=data[i][j];
                            break;
                        }
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
