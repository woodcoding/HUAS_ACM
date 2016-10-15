#include <iostream>
#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MAX 60

char omap[MAX][MAX];    //��ͼ
int time[MAX][MAX];      //��¼��ǰ�㵽�����յ������ѵ�ʱ��(����dfs)  ��time[m+1][0]�����յ㵽����ʱ��
bool went[MAX][MAX];     //��¼bfs���߹��ĵ�
int step[MAX][MAX];     //��¼bfs�еĵ�ǰ����
bool vis[MAX];          //��¼dfs���߹��ĵ�
int val[MAX];           //��ʯ��ֵ

int go[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};      //��������
int w, h, l, m, cas=0, n;                    //��Ҫ�������
int sum, ans;                           //sum��¼��ʯ�ܼ�ֵ��ansΪ��
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
                if(omap[dx][dy]=='@')time[s][0]=step[dx][dy];       //��ǰ�㵽����ʱ��
                else if(omap[dx][dy]=='<')time[s][m+1]=step[dx][dy];    //��ǰ�㵽�յ��ʱ��
                else if(omap[dx][dy]>='A'&&omap[dx][dy]<='J')time[s][omap[dx][dy]-'A'+1]=step[dx][dy];  //��ǰ�㵽��ʯ��ʱ��
                Q.push(make_pair(dx, dy));
            }
        }
    }
}

void dfs(int s, int v, int t){
    if(t>l)return;          //��ʱ
    if(sum==ans)return;     //�Ѿ��������ֵ����֦
    if(s>m){
        if(v>ans)ans=v; //���Գ�ȥ�����Ҹ��¼�ֵ
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
        val[0] = val[m+1] = 0;      //�����յ�ļ�ֵΪ0
        for(int i=1;i<=m;i++){cin>>val[i];sum+=val[i];}
        for(int i=0;i<h;i++)cin>>omap[i];
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(omap[i][j]=='@')bfs(i, j, 0);        //��㵽��ʯ���յ�����ʱ��
            else if(omap[i][j]=='<')bfs(i, j, m+1);     //�յ㵽��ʯ������ʱ��
            else if(omap[i][j]>='A'&&omap[i][j]<='J')bfs(i, j, omap[i][j]-'A'+1);   //��ʯ����ʯ�������յ��ʱ��
        }
        vis[0] = 1;     //�����
        dfs(0, 0, 0);
        if(ans!=-1)printf("Case %d:\nThe best score is %d.\n", cas, ans);
        else printf("Case %d:\nImpossible\n", cas);
        if(cas!=n)cout<<endl;
    }
    return 0;
}
