#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=105;

int res[maxn], lis1[maxn], lis2[maxn], n;

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d", &res[i]);
        }
        for(int i=0;i<n;i++){
            lis1[i]=1;
            for(int j=i-1;j>=0;j--){
                if(res[j]<res[i]){
                    lis1[i]=max(lis1[i], lis1[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            lis2[i]=1;
            for(int j=i+1;j<n;j++){
                if(res[j]<res[i]){
                    lis2[i]=max(lis2[i], lis2[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(lis1[i]+lis2[i], ans);
        }
        printf("%d\n", n-ans+1);
    }
    return 0;
}
