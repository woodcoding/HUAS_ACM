#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=505;

int dis[maxn], inq[maxn], cnt[maxn];
vector<pair<int, int> > E[maxn];
int f, n, m, w;

void init(){
    for(int i=0;i<maxn;i++){
        dis[i]=inf;
        E[i].clear();
        inq[i]=0;
        cnt[i]=0;
    }
}

bool Spfa(int s){
    queue<int> que;
    dis[s]=0;
    inq[s]=1;
    cnt[s]=1;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=0;i<E[u].size();i++){
            int v=E[u][i].first;
            if(dis[v]>dis[u]+E[u][i].second){
                dis[v]=dis[u]+E[u][i].second;
                cnt[v]++;
                if(cnt[v]>=n)return 1;
                if(inq[v])continue;
                que.push(v);
                inq[v]=1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &f);
    while(f--){
        scanf("%d%d%d", &n, &m, &w);
        init();
        int s, e, t;
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &s, &e, &t);
            E[s].push_back(make_pair(e, t));
            E[e].push_back(make_pair(s, t));
        }
        for(int i=0;i<w;i++){
            scanf("%d%d%d", &s, &e, &t);
            E[s].push_back(make_pair(e, -t));
        }
        bool ans=Spfa(1);
        printf("%s\n", ans?"YES":"NO");
    }
    return 0;
}
