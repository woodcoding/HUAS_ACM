#include <iostream>
#include <memory.h>
using namespace std;
const int MAX = 101;
int m, n, i, j, counti;
char omap[MAX][MAX];
int oflag[MAX][MAX];
void Init()
{
    //初始化操作
    for(i=0;i<m;i++)cin>>omap[i];
    memset(oflag,0,sizeof(oflag));
    counti=0;
}
void TestCase()
{
    //调试显示
    int a, b;
    cout<<"\n\n-----Test begin-----\n\n";
    //for(i=0;i<m;i++)cout<<omap[i]<<endl;
    //cout<<"\n--****--\n";
    for(a=0;a<m;a++)for(b=0;b<n;b++){cout<<oflag[a][b];if(b==n-1)cout<<endl;}
    cout<<"\n\n-----Test end-----\n\n";
}
void Dfs(int x, int y, int flag)
{
    //深度搜索
    if(x<0 || y<0 || x>=m || y>=n)return;       //边界判断
    if(omap[x][y] != '@' || oflag[x][y])return; //判断可不可标记
    oflag[x][y]=flag;
    //TestCase();
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++)
            if(dx || dy)Dfs(x+dx, y+dy, flag);      //周围9判断个框框可不可以搜索
}
void Process()
{
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(omap[i][j]=='@' && oflag[i][j]==0)Dfs(i, j, ++counti);
}
int main()
{
    while(cin>>m>>n && m)
    {
        Init();
        Process();
        cout<<counti<<endl;
        //TestCase();
    }
    return 0;
}
