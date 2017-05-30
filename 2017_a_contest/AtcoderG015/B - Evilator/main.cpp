#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int maxn = 100005;
char data[maxn];
int len;

int main()
{
    while(~scanf("%s", &data)){
        len = strlen(data);
        LL ans=(len-1)*2;
        for(int i=1;i<len-1;i++){
            if(data[i]=='U'){
                ans+=(len-1-i);
                ans+=(i*2);
            }
            else{
                ans+=i;
                ans+=(len-1-i)*2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
