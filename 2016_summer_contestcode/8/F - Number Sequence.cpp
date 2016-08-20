#include <iostream>
using namespace std;
const int maxn=50;
int a, b, n;
int ans[maxn];
int main()
{
    while(cin>>a>>b>>n && a+b+n)
    {
        if(n<3)cout<<"1"<<endl;
        else
        {
            int f1=1, f2=1,f3;
            for(int i=1; i<=48; i++)
            {
                f3=(a*f2+b*f1)%7;
                ans[i]=f3;
                f1=f2;
                f2=f3;
            }
            cout<<ans[(n-2)%48]<<endl;
        }
    }
    return 0;
}
