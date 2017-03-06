#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <memory.h>
#define MAX 205
#define INF 0x3f3f3f3f
using namespace std;

struct Res{
    int x, y, r;
}res[MAX];

int t, n, x, y, r, need;
int node[MAX][MAX], inq[MAX];
int d1[MAX], d2[MAX], d3[MAX];

void spfa(int s, int *d){
    queue<int> Q;
    Q.push(s);
    memset(inq, 0, sizeof(inq));
    for(int i=0;i<n;i++)d[i]=INF;
    d[s]=0;
    inq[s] = 1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        inq[u]=0;
        for(int i=0;i<n;i++){
            if(node[u][i]&&u!=i){
                if(d[i]>d[u]+1){
                    d[i]=d[u]+1;
                    if(!inq[i]){
                        inq[i]=1;
                        Q.push(i);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(node, 0, sizeof(node));
        need = INF;
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &res[i].x, &res[i].y, &res[i].r);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pow(res[i].x-res[j].x, 2)+pow(res[i].y-res[j].y, 2)<=pow(res[i].r+res[j].r, 2)){
                    node[i][j]=node[j][i]=1;
                }
            }
        }
        spfa(0, d1);
        spfa(1, d2);
        spfa(2, d3);
        for(int i=0;i<n;i++){
            if(d1[i]==INF||d2[i]==INF||d3[i]==INF)continue;
            else need=min(need,d1[i]+d2[i]+d3[i]);
        }
        if(need==INF)printf("-1\n");
        else printf("%d\n", n-1-need);
    }
    return 0;
}
