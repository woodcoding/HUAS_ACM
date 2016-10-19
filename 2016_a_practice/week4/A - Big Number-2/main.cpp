#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const double e = 2.7182818;
int main()
{
    int x, n, ans;
    cin>>x;
    while(x--){
        cin>>n;
        if(n)ans = int(log10(2*pi*n)/2+n*(log10(n)-log10(e))) + 1;
        else ans=1;
        cout<<ans<<endl;
    }
    return 0;
}
