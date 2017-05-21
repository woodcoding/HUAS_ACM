#include <iostream>
#include <cstdio>
using namespace std;

int t, n, ans, len, tmp, cnt;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        len=0;ans=0;tmp=n;
        while(tmp){
            len++;tmp/=10;
        }
        for(int i=n-len*9;i<n;i++){
            tmp=i;cnt=0;
            while(tmp){
                cnt+=tmp%10;
                tmp/=10;
            }
            if(i+cnt==n){
                ans=i;break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
