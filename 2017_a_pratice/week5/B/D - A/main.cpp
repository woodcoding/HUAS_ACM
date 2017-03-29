#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long t, n, b;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &b);
        for(int i=0;i<9973;i++){
            if((b*i-n)%9973==0){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
