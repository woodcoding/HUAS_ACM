#include <iostream>

using namespace std;

int main()
{
    int res[10] = {6,2,5,5,4,5,6,3,7,6};
    int a, b, ans, t;
    while(cin>>a>>b){
        ans=0;
        for(int i=a;i<=b;i++)
        {
            t=i;
            while(t){
                ans+=res[t%10];
                if(t<10)break;
                t/=10;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
