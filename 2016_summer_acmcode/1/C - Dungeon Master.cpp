#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

const int maxn = 30+2;

class Point
{
public:
    int x;
    int y;
    int z;
    int step;
    Point(int sx, int sy, int sz, int sstep):x(sx),y(sy),z(sz),step(sstep){}
};

char maze[maxn][maxn][maxn];
bool flag[maxn][maxn][maxn];
queue<Point> myqueue;
int local[2][4];
int l, r, c, i, j, k;

void Init()
{
    //初始化清空标记数组,清空列队，读入地图数据
    while(!myqueue.empty())myqueue.pop();
    memset(flag, 0, sizeof(flag));
    for(k=1;k<=l;k++)for(i=1;i<=r;i++)for(j=1;j<=c;j++)
    {
        cin>>maze[i][j][k];
        switch(maze[i][j][k])
        {
            case 'S': local[0][1]=i;local[0][2]=j;local[0][3]=k;break;
            case 'E': local[1][1]=i;local[1][2]=j;local[1][3]=k;break;
        }
    }
}

int check(int cx, int cy, int cz)
{
    return (cx<1||cx>r||cy<1||cy>c||cz<1||cz>l||flag[cx][cy][cz]||maze[cx][cy][cz]=='#')?0:1;
}

int Bfs(int dx, int dy, int dz)
{
    Point point(dx, dy, dz, 0), next(0, 0, 0, 0);
    flag[dx][dy][dz]=true;
    myqueue.push(point);
    while(!myqueue.empty())
    {
        point = myqueue.front();
        myqueue.pop();
        if(point.x==local[1][1]&&point.y==local[1][2]&&point.z==local[1][3])return point.step;
        //cout<<"<"<<point.x<<","<<point.y<<","<<point.z<<">"<<endl;
        for(int dcase=1;dcase<=6;dcase++)
        {
            //向后搜索
            if(dcase==1){next = point;next.x=point.x+1;}
            //向右搜索
            if(dcase==2){next = point;next.y=point.y+1;}
            //向前搜索
            if(dcase==3){next = point;next.x=point.x-1;}
            //向左搜索
            if(dcase==4){next = point;next.y=point.y-1;}
            //向下搜索
            if(dcase==5){next = point;next.z=point.z+1;}
            //向上搜索
            if(dcase==6){next = point;next.z=point.z-1;}
            if(check(next.x, next.y, next.z))
            {
                next.step = point.step+1;
                flag[next.x][next.y][next.z]=true;
                myqueue.push(next);
            }
        }
    }
    return 0;
}

/*
void TestCase()
{
    for(k=1;k<=l;k++)
    {
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)cout<<maze[i][j][k];
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"S=("<<local[0][1]<<","<<local[0][2]<<","<<local[0][3]<<")"<<endl;
    cout<<"E=("<<local[1][1]<<","<<local[1][2]<<","<<local[1][3]<<")"<<endl;
}
*/
int main()
{
    while(cin>>l>>r>>c && l && r && c)
    {
        int go;
        Init();
        //TestCase();
        go = Bfs(local[0][1], local[0][2], local[0][3]);
        if(go)cout<<"Escaped in "<<go<<" minute(s)."<<endl;
        else cout<<"Trapped!"<<endl;
    }
    return 0;
}
