#include <iostream>
#include <stack>
using namespace std;

class Path
{
public:
    int x;
    int y;
    Path(int m, int n):x(m), y(n){}
};

stack<Path> mypath;
int maze[5][5], num, i, j;

void Init()
{
    for(i=0;i<5;i++)for(j=0;j<5;j++){cin>>num;if(num)num=-1;maze[i][j]=num;}
    while(!mypath.empty())mypath.pop();
}

void Bfs(int x, int y, int flag)
{
    if(x<0||x>=5||y<0||y>=5)return;
    maze[x][y]=flag;
    //cout<<x<<","<<y<<endl;
    for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)
    {
        if((!dx || !dy) && (dx+dy) && (maze[x+dx][y+dy]==0 || maze[x+dx][y+dy]>maze[x][y]))
            Bfs(x+dx,y+dy,maze[x][y]+1);
    }
}
void PushMe(int px, int py)
{
    if(px<0||px>=5||py<0||py>=5)return;
    mypath.push(Path(px, py));
    for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)
    {
        if(dx+dy && (!dx&&dy || !dy&&dx) && maze[px+dx][py+dy]==maze[px][py]-1)
            PushMe(px+dx, py+dy);
    }
}
void Print()
{
    while(!mypath.empty())
    {
        cout<<"("<<mypath.top().x<<", "<<mypath.top().y<<")"<<endl;
        mypath.pop();
    }
}
void TestCase()
{
    cout<<"\n----Begin----\n";
    /*Test path pic
    for(i=0;i<5;i++)for(j=0;j<5;j++)
    {
        cout<<maze[i][j]<<"\t";
        if(j==4)cout<<endl;
    }
    */
    cout<<"\n-----End-----\n";
}
int main()
{
    Init();
    Bfs(0,0,1);
    PushMe(4,4);
    Print();
    //TestCase();
}

