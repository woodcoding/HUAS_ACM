#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=600;
const int maxp=40;
int t, n, k1, k2, k3, a, b, c;
double pk[maxp], all, sum, A[maxn], B[maxn];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(pk, 0, sizeof(pk));
        all=k1*k2*k3;
        sum=k1+k2+k3;
        pk[0]=1.0/all;
        for(int i=1;i<=k1;i++){
            for(int j=1;j<=k2;j++){
                for(int k=1;k<=k3;k++){
                    if(i==a&&j==b&&k==c)continue;
                    pk[i+j+k]++;
                }
            }
        }
        for(int i=3;i<=sum;i++)pk[i]/=all;
        for(int i=n;i>=0;i--){
            for(int j=3;j<=sum;j++){
                A[i]+=(pk[j]*A[i+j]);
                B[i]+=(pk[j]*B[i+j]);
            }
            A[i]+=pk[0];
            B[i]++;
        }
        printf("%.15lf\n", B[0]/(1.0-A[0]));
    }
    return 0;
}
