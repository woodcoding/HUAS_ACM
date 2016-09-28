#include <iostream>

using namespace std;

int check(int x){
    return (x&(x-1))?0:1;
}

int main()
{
    int x, ans;
    while(cin>>x){
        if(check(x))ans=0;
        else if(x&1)ans=(x-1)/2;
        else{
            int y=1;
            while(y<=x)y<<=1;
            ans=(x-y/2)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
