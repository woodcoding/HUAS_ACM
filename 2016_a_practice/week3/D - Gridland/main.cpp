#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m, n, cas;
    double ans;
    cin>>cas;
    for(int i=1;i<=cas;i++){
        cin>>m>>n;
        ans = m*n;
        if(m%2 && n%2)ans+=0.41;
        printf("Scenario #%d:\n%.2lf\n\n", i, ans);
    }
    return 0;
}
