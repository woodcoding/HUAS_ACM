#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxm=100+1;

int n, num, i, j;
int node[maxm][maxm], dis[maxm], flag[maxm];

void Init()
{
    int x, y, val;
    num=n*(n-1)/2;
    memset(flag, 0, sizeof(flag));      //��ʼ��ÿ���㶼���ڼ�����
    memset(node, INF, sizeof(node));    //��ʼ����������Ϊ�����
    memset(dis, -1, sizeof(dis));       //��ʼ��Ϊ-1��˼Ϊ��ǰ�㵽����û�о���
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d", &x,&y,&val);  //��ñ�Ȩֵ
        node[x][y]=node[y][x]=val;
    }
}

int Prim()
{
    int sum=0;
    dis[1]=0;
    flag[1]=1;
    for(i=2;i<=n;i++)       //��ʼ���������㵽��㼯�ϵ�λ��
        dis[i]=node[1][i];
    for(i=1;i<n;i++)
    {
        int tmin=999999, cur=-1;
        for(j=2;j<=n;j++)
        {
            if(!flag[j]&&(dis[j]<tmin))    //�Ҿ��뵱ǰ������С��Ȩ
                {
                    tmin=dis[j];
                    cur=j;
                }
        }
        flag[cur]=1;    //�����Ȩ���뼯����
        sum+=dis[cur];
        for(j=2;j<=n;j++)       //���¸����㵽���ϵľ���
        {
            if(!flag[j]&&node[cur][j]<dis[j])
                dis[j]=node[cur][j];
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        Init();
        int ans=Prim();
        printf("%d\n", ans);
    }
    return 0;
}
