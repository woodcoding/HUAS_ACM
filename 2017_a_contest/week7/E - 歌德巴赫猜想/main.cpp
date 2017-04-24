#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cmath>
using namespace std;

const int maxn=1000000;
int z[maxn], cntz[maxn], n, cnt;

void Init(){
    memset(z, 0, sizeof(z));
    memset(cntz, 0, sizeof(cntz));
    z[0]=-1;z[1]=1;
    cntz[0]=1;cnt++;
    for(int i=3;i<=maxn;i++){
        int flag=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){flag=0;break;}
        }
        if(flag){
            z[i]=1;
            cntz[cnt++]=i;
        }
    }
//    for(int i=0;i<cnt;i++){
//        cout<<cntz[i]<<" ";
//    }
//    cout<<endl;
}

int main()
{
    Init();
    while(~scanf("%d", &n)){
        int i=0;
        while(cntz[i++]<n/2){
            int other=n-cntz[i];
            if(z[other]==1){
                printf("%d %d\n", cntz[i], other);
                break;
            }
        }
    }
    return 0;
}
