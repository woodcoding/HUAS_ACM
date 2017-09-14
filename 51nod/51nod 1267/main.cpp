#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct Node{
    int a, b, sum;
    Node(){}
    Node(int ca, int cb){a=ca, b=cb;}
    bool operator<(const Node & cmp) const{
        return sum<cmp.sum;
    }
};

map<int, int> cnt;

const int maxn=1005;
int n, data[maxn];
Node add[maxn*maxn];
int sum[maxn*maxn];

int main()
{
    while(~scanf("%d", &n)){
        cnt.clear();
        for(int i=0;i<n;i++){
            scanf("%d", &data[i]);
            cnt[data[i]]++;
        }
        int pos=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                add[pos].a=data[i];
                add[pos].b=data[j];
                sum[pos]=data[i]+data[j];
                add[pos++].sum=data[i]+data[j];
            }
        }
        sort(add, add+pos);
        sort(sum, sum+pos);
        int ok=0;
        for(int i=0;i<pos;i++){
            //cout<<"*"<<add[i].sum<<endl;
            int start=lower_bound(sum, sum+pos, -add[i].sum)-sum;
            if(add[i].sum!=-sum[start])continue;
            //cout<<add[i].a<<"  "<<add[i].b<<"  "<<add[i].sum<<endl;
            int ta=sum[start]-add[i].a;
            int tb=sum[start]-add[i].b;
            if(!cnt[ta]&&!cnt[tb]){
                ok=1;break;
            }
        }
        printf("%s\n", ok?"Yes":"No");
    }
    return 0;
}
