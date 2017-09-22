#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int x;
    while(~scanf("%d", &x)){
        int n=sqrt(x), cnt=0;
        for(int i=0;i<n;i++){
            int sq=sqrt(x-i*i);
            if(sq&&sq<i)break;
            if(sq*sq==x-i*i){
                printf("%d %d\n", i, sq);
                cnt++;
            }
        }
        if(!cnt)printf("No Solution\n");
    }
    return 0;
}
