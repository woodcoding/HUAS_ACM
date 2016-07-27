#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

const int maxn=1000+1;
const int inf=9999999;

double omap[maxn][maxn];
bool flag[maxn];
int x[maxn], y[maxn];
int i, j, icase=1, n;

void Init()
{
    memset(flag, 0, sizeof(flag));
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)omap[i][j]=inf;      //初始化最大值
    for(i=1;i<=n;i++)scanf("%d%d", &x[i], &y[i]);  //获得坐标值
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        omap[i][j]=sqrt((double)(x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i])); //获得距离值
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)printf("%.1lf ",omap[i][j]);
        cout<<endl;
    }
    cout<<endl;
    */
}

double Prim()
{
    double imax=0, minlen;
    int t;
    for(i=1;i<n;i++)
    {
        minlen=999999;
        for(j=2;j<=n;j++)
        {
            if(!flag[j]&&omap[1][j]<minlen)
            {
                minlen=omap[1][j];
                t=j;
            }
        }
        flag[t]=1;
        if(minlen>imax)imax=minlen;	//判断是否跳到目的地
        if(t==2)return imax;
        //cout<<"--->max="<<imax<<"**t="<<t<<endl;
        for(j=2;j<=n;j++)
        {
            if(!flag[j] && omap[t][j]<omap[1][j])
            {
                omap[1][j]=omap[t][j];
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &n)!=EOF && n)
    {
        Init();
        double ans=Prim();
        printf("Scenario #%d\n", icase++);
        printf("Frog Distance = %.3lf\n\n", ans);		//两个换行！！！
    }
    return 0;
}
