#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long

int mod7[7] = {3241,1324,1234,2341,1243,1342,2134};
int mod72[7] = {4312,3214,4132,3412,2314,3421,3142};
bool flag[5];
int len, k, t, qmod, x;
char num[21];
LL q;

bool check(){
    //判断和原来的是否相同
    int tlen = strlen(num)-1;
    int tqmod=0, tx=0;
    for(int i=0;i<4;i++){
        tqmod += pow(10.0, tx++)*(num[tlen-i]-'0');
    }
    if(qmod==tqmod)return 1;
    return 0;
}

int intlen(int xx){
    int xlen=0;
    while(xx){
        xlen++;
        xx/=10;
    }
    return xlen;
}

int main()
{
    cin>>k;
    getchar();
    while(k--)
    {
        memset(flag, 0, sizeof(flag));
        gets(num);
        q = 0;
        x = 0;
        for(int i=strlen(num)-1;i>=0;i--){
            t = num[i]-'0';
            if(t>=1 && t<=4 && !flag[t])flag[t]=1;
            else q+=pow(10.0, x++)*t;
        }
        int qend;
        qend = ((q%7)*(10000%7))%7;
        qmod = mod7[(7-qend)%7];
        if(q)cout<<q;
        if(check())qmod = mod72[(7-qend)%7];
        cout<<qmod;
        if(!q && strlen(num)>4){
            for(int i=5;i<=strlen(num);i++)cout<<0;
        }
        if(q && intlen(q)+4<strlen(num)){
            for(int i=intlen(q)+5;i<=strlen(num);i++)cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
