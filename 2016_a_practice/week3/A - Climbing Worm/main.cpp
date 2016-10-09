#include <iostream>

using namespace std;

int main()
{
    int time, cur, a, b, c;
    while(cin>>a>>b>>c && a+b+c){
        cur = 0;
        time = 0;
        while(1){
            cur+=b;
            time++;
            if(cur>=a)break;
            cur-=c;
            time++;
        }
        cout<<time<<endl;
    }
    return 0;
}
