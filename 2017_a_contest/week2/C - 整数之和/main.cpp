#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 4005

int ab[MAX*MAX], cd[MAX*MAX];
int a[MAX], b[MAX], c[MAX], d[MAX];
int n, ans;

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ab[i*n+j]=a[i]+b[j];
                cd[i*n+j]=c[i]+d[j];
            }
        }
        sort(ab, ab+n*n);
        sort(cd, cd+n*n);
        ans=0;
        int pos=n*n-1;
        for(int i=0;i<n*n;i++){
            while(ab[i]+cd[pos]>0&&pos>=0)pos--;
            if(pos<0)break;
            int t=pos;
            while(ab[i]+cd[t]==0&&t>=0){
                ans++;t--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
