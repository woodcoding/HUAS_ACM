#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 1025
int cmd, s, x, y, a, l, b, r, t, ans;
int num[MAX][MAX];

int lowbit(int lx){
    return lx&(-lx);
}

void add(int ax, int ay, int v){    ///二维树状数组更新
    for(int i=ax;i<=s;i+=lowbit(i))
        for(int j=ay;j<=s;j+=lowbit(j))
            num[i][j]+=v;
}

int q(int qx, int qy){          ///二维树状数组查询
    int sum=0;
    for(int i=qx;i>0;i-=lowbit(i))
        for(int j=qy;j>0;j-=lowbit(j))
            sum+=num[i][j];
    return sum;
}

int main()
{
    while(cin>>cmd){
        if(cmd==0){
            cin>>s;
            memset(num, 0, sizeof(num));
        }
        else if(cmd==1){
            cin>>x>>y>>a;
            x++;y++;
            add(x, y, a);
        }
        else if(cmd==2){
            cin>>l>>b>>r>>t;
            l++;b++;r++;t++;
            cout<<q(r, t)-q(r, b-1)-q(l-1, t)+q(l-1, b-1)<<endl;
        }
        else if(cmd==3)break;
    }
    return 0;
}
