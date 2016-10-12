#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX 5005

struct Wood{
    int l, w;
}wood[MAX];

bool cmp(Wood a, Wood b){
    return a.l<b.l || (a.l==b.l && a.w<b.w);
}

int main()
{
    int T, n, ans, re;
    bool used[MAX];
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>wood[i].l>>wood[i].w;
        sort(wood, wood+n, cmp);
        ans = 0;
        re = n;
        memset(used, 0, sizeof(used));
        int flag;
        while(re){
            bool s=1;
            for(int i=0;i<n;i++){
                if(!used[i]){
                    if(s){      //找LIS第一个
                        ans++;
                        re--;
                        s = 0;
                        flag = i;
                        used[i] = 1;
                    }
                    else{       //找LIS串
                        if(!(wood[i].l>=wood[flag].l && wood[i].w>=wood[flag].w))continue;
                        else{
                            used[i] = 1;
                            re--;
                            flag = i;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
