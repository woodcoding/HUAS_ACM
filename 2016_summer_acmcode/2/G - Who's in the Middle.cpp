#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=10000;
int cows[maxn];
int n;

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)cin>>cows[i];
        sort(cows, cows+n);
        cout<<cows[(n-1)/2]<<endl;
    }
    return 0;
}
