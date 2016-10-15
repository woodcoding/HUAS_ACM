#include <iostream>
#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MAX 60

char omap[MAX][MAX];    //地图
int time[MAX][MAX];      //记录当前点到起点和终点所花费的时间(用于dfs)  如time[m+1][0]代表终点到起点的时间
bool went[MAX][MAX];     //记录bfs中走过的点
int step[MAX][MAX];     //记录bfs中的当前步长
bool vis[MAX];          //记录dfs中走过的点
int val[MAX];           //宝石价值

int go[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};      //方向数组
int w, h, l, m, cas=0, n;                    //必要输入参数
int sum, ans;                           //sum记录宝石总价值，ans为答案
queue<pair<int, int> > Q;

bool chk(int x, int y){
    if(x<0 || y<0 || x>=h ||y>=w || omap[x][y]=='*' || went[x][y])return 0;
    return 1;
}

void bfs(int x, int y, int s){
    while(!Q.empty())Q.pop();
    memset(went, 0, sizeof(went));
    memset(step, 0, sizeof(step));
    Q.push(make_pair(x, y));
    went[x][y] = 1;
    step[x][y] = 0;
    while(!Q.empty()){
        pair<int, int> u = Q.front();Q.pop();
        for(int i=0;i<4;i++){
            int dx = u.first+go[i][0];
            int dy = u.second+go[i][1];
            if(chk(dx, dy)){
                went[dx][dy] = 1;
                step[dx][dy] = step[u.first][u.second]+1;
                if(omap[dx][dy]=='@')time[s][0]=step[dx][dy];       //当前点到起点的时间
                else if(omap[dx][dy]=='<')time[s][m+1]=step[dx][dy];    //当前点到终点的时间
                else if(omap[dx][dy]>='A'&&omap[dx][dy]<='J')time[s][omap[dx][dy]-'A'+1]=step[dx][dy];  //当前点到宝石的时间
                Q.push(make_pair(dx, dy));
            }
        }
    }
}

void dfs(int s, int v, int t){
    if(t>l)return;          //超时
    if(sum==ans)return;     //已经获得最大价值，剪枝
    if(s>m){
        if(v>ans)ans=v; //可以出去，并且更新价值
        return;
    }
    for(int i=0;i<=m+1;i++){
        if(vis[i] || time[s][i]==0)continue;
        vis[i] = 1;
        dfs(i, v+val[i], t+time[s][i]);
        vis[i] = 0;
    }
}

int main()
{
    cin>>n;
    while(++cas<=n){
        ans = -1;
        sum = 0;
        memset(time, 0, sizeof(time));
        memset(vis, 0, sizeof(vis));
        cin>>w>>h>>l>>m;
        val[0] = val[m+1] = 0;      //起点和终点的价值为0
        for(int i=1;i<=m;i++){cin>>val[i];sum+=val[i];}
        for(int i=0;i<h;i++)cin>>omap[i];
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(omap[i][j]=='@')bfs(i, j, 0);        //起点到宝石和终点的最短时间
            else if(omap[i][j]=='<')bfs(i, j, m+1);     //终点到宝石和起点的时间
            else if(omap[i][j]>='A'&&omap[i][j]<='J')bfs(i, j, omap[i][j]-'A'+1);   //宝石到宝石、起点和终点的时间
        }
        vis[0] = 1;     //起点标记
        dfs(0, 0, 0);
        if(ans!=-1)printf("Case %d:\nThe best score is %d.\n", cas, ans);
        else printf("Case %d:\nImpossible\n", cas);
        if(cas!=n)cout<<endl;
    }
    return 0;
}
