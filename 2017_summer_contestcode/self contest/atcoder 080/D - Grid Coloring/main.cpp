#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=10005;
int ans[maxn][maxn];
int n, h, w, data[maxn*2];

int main()
{
    while(~scanf("%d%d", &h, &w)){
        scanf("%d", &n);
        int cnt=0, now=1, pos=1;
        int i=0, j=0;
        for(int k=1;k<=n;k++){
            scanf("%d", &data[k]);
            while(data[k]--){
                ans[i][j]=k;
                if(i%2==0){
                    j++;
                    if(j==w){
                        i++;
                        j=w-1;
                    }
                }
                else{
                    j--;
                    if(j==-1){
                        i++;
                        j=0;
                    }
                }
            }
        }
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                printf("%d", ans[i][j]);
                printf("%s", j==w-1?"\n":" ");
            }
        }
    }
    return 0;
}
