#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point
{
    int x,y,len;
};

const int maxn=100+10;
Point point[maxn];
int flag[maxn];
int n, i, j, now;
char ch1, ch2;

void Init()
{
    int num1, num2, x, y;
    now=0;
    for(i=1;i<=n-1;i++)
    {
       cin>>ch1>>num1;
       for(j=1;j<=num1;j++)
       {
           cin>>ch2>>num2;
           now++;
           point[now].x=ch1-'A'+1;
           point[now].y=ch2-'A'+1;
           point[now].len=num2;
       }
    }
    for(i=0;i<=now;i++)flag[i]=i;
}

bool cmp(Point a, Point b)
{
    return a.len<b.len;
}

int Find(int x)
{
    if(flag[x]==x)return x;
    flag[x]=Find(flag[x]);
    return flag[x];
}

int Kus()
{   ///不懂的看“还是畅通工程”
    int sum=0;
    for(i=1;i<=now;i++)
    {
        int fa=Find(point[i].x);
        int fb=Find(point[i].y);
        if(fa==fb)continue;
        else
        {
            sum+=point[i].len;
            if(fa>fb)
                flag[fb]=fa;
            else
                flag[fa]=fb;
        }
    }
    return sum;
}

int main()
{
    while(cin>>n && n)
    {
        Init();
        sort(point+1, point+now+1, cmp);
        int ans=Kus();
        cout<<ans<<endl;
    }
    return 0;
}