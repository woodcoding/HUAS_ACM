#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1000005;
int n;
int data[maxn];

int main()
{
    while(~scanf("%d", &n)){
        int a=0, b=0, c=0;
        for(int i=0;i<n;i++){
            scanf("%d", &data[i]);
            if(data[i]%4==0)a++;
            else if(data[i]%2==0)b++;
            else c++;
        }
        int ans=0;
        if(b%2==0)c--;
        if(a>=c)ans=1;
        printf("%s\n", ans?"Yes":"No");
    }
    return 0;
}
