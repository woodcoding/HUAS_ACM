#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

const int maxn=100+2;
int omap[maxn][maxn];   //��ׯ�����¼ͼ
bool flag[maxn];         //��ׯ���ʱ�Ǽ�¼
int n, i, j;

void Init()
{
    int num=n*(n-1)/2;      //��������
    int x, y, len;
    memset(omap, 0, sizeof(omap));      //��ʼ���������
    memset(flag, 0, sizeof(flag));
    for(i=1;i<=num;i++)
    {
        scanf("%d%d%d", &x,&y,&len);
        omap[x][y]=omap[y][x]=len;      //x->y�ľ���==y->x�ľ���
    }
}

int Prim()
{
    int sum=0;
    int minlen, t;
    for(i=1;i<n;i++)        //ע�⣬ѭ��n-1��
    {
        minlen=100000;
        for(j=2;j<=n;j++)
        {
            if(!flag[j] && omap[1][j]<minlen)     //��������û�б����ʣ�������С����Сֵ
            {
                minlen=omap[1][j];
                t=j;        //��ǰ�㸳ֵ��t��
            }
        }
        flag[t]=1;      //��ǵ�ǰ���Ѿ�������
        sum+=minlen;
        //cout<<"-->minlen:"<<minlen<<endl;
        for(j=2;j<=n;j++)
        {
            //�����ǰ�㵽�¸���ľ���С�ڸ������ľ�����ô���¸����¸���ľ���
            if(!flag[j] && omap[t][j]<omap[1][j])omap[1][j]=omap[t][j];
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
