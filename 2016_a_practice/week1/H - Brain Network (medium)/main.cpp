#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000+10
int dis[MAX];
int n, m, s, e;
int inf=10e6;
vector <pair<int, int> > node[MAX];
priority_queue <pair<int, int> > Q;


int init(){
    for(int i=1;i<=n;i++){
        node[i].clear();
        dis[i]=inf;
    }
    int u, v;
    for(int i=0;i<m;i++){
        scanf("%d%d", &u, &v);
        node[u].push_back(make_pair(v, 1));
        node[v].push_back(make_pair(u, 1));
        if(!i)s=u;
    }
    dis[s] = 0;
    Q.push(make_pair(-dis[s], s));
}

int maxp(){
    while(!Q.empty())
    {
        int u=Q.top().second;
        Q.pop();
        for(int i=0;i<node[u].size();i++)
        {
            int v=node[u][i].first;
            if(dis[v]>dis[u]+node[u][i].second)
            {
                dis[v]=dis[u]+node[u][i].second;
                Q.push(make_pair(-dis[v], v));
            }
        }
    }
    int td=0, ti=0;
    for(int i=1;i<=n;i++){
        if(dis[i]!=inf && dis[i]>td){
            td = dis[i];
            ti = i;
        }
    }
    return ti;
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        e = maxp();
        for(int i=1;i<=n;i++)dis[i]=inf;
        s = e;
        dis[s] = 0;
        while(!Q.empty())Q.pop();
        Q.push(make_pair(-dis[s], s));
        e = maxp();
        cout<<dis[e]<<endl;
    }
    return 0;
}
