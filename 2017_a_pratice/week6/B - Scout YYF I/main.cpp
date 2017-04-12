#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn=15;
const int maxm=2;
int n, res[maxn], l, r;
double p, ans;

struct Matrix{
    double ret[maxm][maxm];
};

Matrix I={1, 0, 0, 1};
Matrix A={p, 1, 1-p, 0};

Matrix operator*(Matrix a, Matrix b){
    Matrix c;
    for(int i=0;i<maxm;i++){
        for(int j=0;j<maxm;j++){
            double tmp=0;
            for(int k=0;k<maxm;k++){
                tmp+=a.ret[i][k]*b.ret[k][j];
            }
            c.ret[i][j]=tmp;
        }
    }
    return c;
}

Matrix operator^(Matrix c, int n){
    Matrix ans=I, a=c;
    while(n){
        if(n%2)ans=ans*a;
        n/=2;
        a=a*a;
    }
    return ans;
}

int main()
{
    res[0]=0;
    while(~scanf("%d %lf", &n, &p)){
        for(int i=1;i<=n;i++){
            scanf("%d", &res[i]);
        }
        sort(res, res+n);
        ans=1;l=0;
        A.ret[0][0]=p;A.ret[0][1]=1;
        A.ret[1][0]=1-p;A.ret[1][1]=0;
        for(int i=1;i<=n;i++){
            if(res[i]-res[i-1]==1){ans=0;break;}
            int len=res[i]-res[i-1]-2;
            Matrix tmp=A^len;
            ans*=(tmp.ret[0][0]*(1-p));
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}
