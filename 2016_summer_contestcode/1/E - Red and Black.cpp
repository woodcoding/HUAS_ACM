#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

const int maxn=20+4;

class Point
{
public:
    int x;
    int y;
    Point(int px, int py):x(px),y(py){}
};

int w, h, mx, my;
const int direct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char omap[maxn][maxn];
int flag[maxn][maxn];

void Init()
{
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)
    {
        cin>>omap[i][j];
        if(omap[i][j]=='@'){mx=i;my=j;}
    }
    memset(flag, 0, sizeof(flag));
}

int check(int cx, int cy)
{
    return (cx<=0||cx>h||cy<=0||cy>w||omap[cx][cy]=='#'||flag[cx][cy])?false:true;
}

void Bfs(int bx, int by)
{
    queue<Point> myqueue;
    Point point(bx, by), next(0, 0);
    flag[bx][by]=1;
    myqueue.push(point);
    while(!myqueue.empty())
    {
        point=myqueue.front();
        myqueue.pop();
        //cout<<"<"<<point.x<<","<<point.y<<">"<<endl;
        for(int dx=0;dx<4;dx++)
        {
            next.x=point.x+direct[dx][0];
            next.y=point.y+direct[dx][1];
            if(check(next.x, next.y))
            {
                flag[next.x][next.y]=1;
                myqueue.push(next);
            }
        }
    }
}

void Print()
{
    int ans=0;
    for(int ax=1;ax<=h;ax++)
    {
        for(int ay=1;ay<=w;ay++)if(flag[ax][ay])ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    while(cin>>w>>h && w && h)
    {
        Init();
        //cout<<"mx="<<mx<<",my="<<my<<endl;
        Bfs(mx, my);
        Print();
    }
    return 0;
}
