#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
using namespace std;

const int maxn=14;
int time[maxn], t, n, m, prb, hh, mm, ans, all;
char cmd[4];
bool ac[maxn];

int main()
{
    scanf("%d", &t);
    while(t--){
        memset(time, 0, sizeof(time));
        memset(ac, 0, sizeof(ac));
        ans=all=0;
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d %d:%d %s", &prb, &hh, &mm, &cmd);
            prb-=1000;
            if(!ac[prb]){
                int tm=hh*60+mm;
                if(strcmp(cmd, "AC")==0){
                    time[prb]+=tm;
                    ac[prb]=1;
                }
                else time[prb]+=20;
            }
            if(ac[prb]&&time[prb]!=-1){
                ans+=time[prb];
                all++;
                time[prb]=-1;
            }
        }
        printf("%d %d\n", all, ans);
    }
    return 0;
}
