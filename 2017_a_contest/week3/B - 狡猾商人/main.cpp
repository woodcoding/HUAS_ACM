#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1005

int w, n, m, s, t, v;
bool ans;
int zb[101][101];
int flag[101][101];

struct Res{
    int s, t, v, pd;

    bool operator<(const Res&x) const{
        return pd<x.pd;
    }
} res[MAX];

int main()
{
    scanf("%d", &w);
    while(w--){
        scanf("%d%d", &n, &m);
        ans=1;
        memset(zb, 0, sizeof(zb));
        memset(flag, 0, sizeof(flag));
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &s, &t, &v);
            res[i].s=s;res[i].t=t;res[i].v=v;
            res[i].pd=t-s;
            flag[s][t]=1;
            zb[s][t]=v;
        }
        sort(res, res+m);
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                if(res[i].s==res[j].s&&res[i].t>res[j].t){
                    s=res[j].t+1;
                    t=res[i].t;
                    v=res[i].v-res[j].v;
                    if(t<s)continue;
                    if(flag[s][t]&&zb[s][t]!=v){
                        ans=0;
                        break;
                    }
                    else{
                        zb[s][t]=v;
                        flag[s][t]=1;
                    }
                }
                if(res[i].t==res[j].t&&res[i].s<res[j].s){
                    s=res[i].s;
                    t=res[j].s-1;
                    v=res[i].v-res[j].v;
                    if(t<s)continue;
                    if(flag[s][t]&&zb[s][t]!=v){
                        ans=0;
                        break;
                    }
                    else{
                        zb[s][t]=v;
                        flag[s][t]=1;
                    }
                }
            }
            if(!ans)break;
        }
        if(ans)printf("true\n");
        else printf("false\n");
    }
    return 0;
}
