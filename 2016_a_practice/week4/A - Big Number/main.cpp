#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, x;
    double ans;
    cin>>n;
    while(n--){
        cin>>x;
        ans=1;
        for(int i=1;i<=x;i++)ans+=log10(i);
        cout<<(int)ans<<endl;
    }
    return 0;
}
