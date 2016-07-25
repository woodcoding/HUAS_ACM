#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=1000+1;
const int INF=9999999;
int omap[maxn][maxn], dis[maxn];
bool vis[maxn];
int t, n, i, j;
int x, y, len;

void Init()
{
    memset(omap, INF, sizeof(omap));
    memset(dis, INF, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d", &x, &y, &len);
        if(len<omap[x][y])
        {
            omap[x][y]=omap[y][x]=len;      //ȥ��
        }
    }
}

void Process()
{
    dis[1]=0;   //��һ��������Լ�Ϊ0
    for(i=1;i<=n;i++ )        //ѭ��N����
    {
        int cur=-1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&(cur==-1||dis[j]<dis[cur]))  //�Ҿ���1��С����Զλ�ã����ֵ�����Լ���ʼ��
                cur=j;
        }
        vis[cur]=1;     //��ǵ�ǰλ���Ѿ�������
        for(j=1;j<=n;j++)
        {
            //���һ��λ��û�б����ʲ���ͨ�����λ�ü�ӻ���˱ȵ�ǰλ�ø��̵ľ���
            if(!vis[j]&&dis[j]>dis[cur]+omap[cur][j])
                dis[j]=dis[cur]+omap[cur][j];
        }
    }
}

int main()
{
    while(scanf("%d%d", &t, &n)!=EOF)
    {
        Init();
        Process();
        printf("%d\n", dis[n]);
    }
    return 0;
}
