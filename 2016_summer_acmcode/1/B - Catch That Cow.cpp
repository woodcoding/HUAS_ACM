#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

const int maxn=100000+10;

class Point
{
public:
    int local;
    int step;
};

int farmer, cow, result;
bool line[maxn];
queue<Point> orgin;

void Init()
{
    //��ʼ������������ͼ��ȫ������Ϊû����,��������ж�
    memset(line, 0, sizeof(line));
    while(!orgin.empty())orgin.pop();
    result = 0;
}
int check(int x)
{
    return (x<0||x>100000||line[x])?0:1;
}
void Bfs(int now)
{
    Point point, next;
    //��һ��λ�ÿ�ʼ����
    point.local=now;
    point.step=0;
    line[now]=true;
    orgin.push(point);
    while(!orgin.empty())
    {
        point = orgin.front();
        orgin.pop();
        if(point.local==cow){result=point.step;break;}      //����ҵ�ţ���˳�ѭ��֮������𰸡�
        next = point;
        for(int y=1;y<=3;y++)
        {
            if(y==1)next.local = point.local+1; //ǰ��һ������
            if(y==2)next.local = point.local-1; //����һ������
            if(y==3)next.local = point.local*2; //��������
            if(check(next.local))
            {
                next.step = point.step+1;
                line[next.local]=true;
                orgin.push(next);
            }
        }
    }
}
int main()
{
    while(cin>>farmer>>cow)
    {
        Init();
        Bfs(farmer);
        cout<<result<<endl;
    }
    return 0;
}
