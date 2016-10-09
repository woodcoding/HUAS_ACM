#include <iostream>
#define MAX 110
using namespace std;

int main()
{
    int m, n, ans, t, x;
    while(cin>>n>>m){
        ans=0;
        for(int i=0;i<n;i++){
            t=10e9;
            for(int j=0;j<m;j++){
                cin>>x;
                t=x<t?x:t;
            }
            ans=ans>t?ans:t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
