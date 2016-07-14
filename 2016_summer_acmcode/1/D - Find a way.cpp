#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

//定义位置类
class Point
{
public:
    int x;
    int y;
    Point(int px, int py):x(px),y(py){}
};

const int maxn = 200+10;
const int direct[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int yx, yy, mx, my, n, m;
char omap[maxn][maxn];
int ymap[maxn][maxn];
int mmap[maxn][maxn];
bool flag[maxn][maxn];
queue<Point> kfc;

void Init()
{
    memset(ymap, 0, sizeof(ymap));
    memset(mmap, 0, sizeof(mmap));
    for(int di=1;di<=n;di++)for(int dj=1;dj<=m;dj++)
    {
        cin>>omap[di][dj];
        switch(omap[di][dj])
        {
            case 'Y':yx=di;yy=dj;break;
            case 'M':mx=di;my=dj;break;
            case '@':kfc.push(Point(di, dj));break;
        }
    }
}

bool check(int cx, int cy)
{
    return (cx<1||cx>n||cy<1||cy>m||omap[cx][cy]=='#'||flag[cx][cy])?false:true;
}

void Bfs(int bx, int by, int xmap[maxn][maxn])
{
    queue<Point> myqueue;
    memset(flag, 0, sizeof(flag));
    Point point(bx, by), next(0, 0);
    flag[bx][by]=true;
    myqueue.push(point);
    while(!myqueue.empty())
    {
        point = myqueue.front();
        myqueue.pop();
        for(int dx=0;dx<4;dx++)
        {
            next.x = point.x+direct[dx][0];
            next.y = point.y+direct[dx][1];
            if(check(next.x, next.y))
            {
                xmap[next.x][next.y]=xmap[point.x][point.y]+1;
                flag[next.x][next.y]=true;
                myqueue.push(next);
            }
        }
    }
}

void Print()
{
    int ans=100000, tans;
    while(!kfc.empty())
    {
        Point test = kfc.front();
        kfc.pop();
        tans = ymap[test.x][test.y] + mmap[test.x][test.y];
        if(ymap[test.x][test.y] && mmap[test.x][test.y])ans  = ans>tans?tans:ans;
    }
    cout<<ans*11<<endl;
}

int main()
{
    while(cin>>n>>m)
    {
        Init();
        Bfs(yx, yy, ymap);
        Bfs(mx, my, mmap);
        Print();
    }
    return 0;
}
