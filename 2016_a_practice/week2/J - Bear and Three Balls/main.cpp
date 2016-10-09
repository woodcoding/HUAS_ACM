#include <iostream>
#include <memory.h>
#define MAX  1000+10
using namespace std;

int main()
{
    int num[MAX], n, x, ans;
    while(cin>>n && n){
        memset(num, 0, sizeof(num));
        ans=0;
        while(n--){
            cin>>x;
            num[x]++;
        }
        for(int i=1;i<=998;i++){
            if(num[i] && num[i+1] && num[i+2]){
                ans=1;
                break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
