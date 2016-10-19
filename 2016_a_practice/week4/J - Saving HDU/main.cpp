#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 110
struct Node{
    int v, m;
}node[MAX];

bool cmp(Node a, Node b){
    return a.m>b.m;
}

int main()
{
    int v, n, ans;
    while(cin>>v && v){
        cin>>n;
        ans = 0;
        for(int i=0;i<n;i++)cin>>node[i].m>>node[i].v;
        sort(node, node+n, cmp);
        for(int i=0;i<n;i++){
            if(!v)break;
            if(v>=node[i].v){
                ans+=node[i].m*node[i].v;
                v-=node[i].v;
            }
            else{
                ans+=node[i].m*v;
                v=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
