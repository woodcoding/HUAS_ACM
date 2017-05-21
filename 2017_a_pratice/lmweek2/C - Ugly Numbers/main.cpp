#include <iostream>
#include <cmath>
#include <set>
#include <cstdio>
using namespace std;

set<int> data;

int main()
{
    for(int i=0;i<40;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                data.insert(pow(2.0, i*1.0)*pow(3.0, j*1.0)*pow(5.0, k*1.0));
            }
        }
    }
    int cnt=0;
    int ans;
    for(set<int>::iterator it=data.begin();it!=data.end();it++){
        ++cnt;
        if(cnt==1500){ans=*it;break;}
    }
    printf("The 1500'th ugly number is %d.\n", ans);
    return 0;
}
