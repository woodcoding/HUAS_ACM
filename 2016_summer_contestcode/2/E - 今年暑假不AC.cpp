#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Time
{
    int tBegin;
    int tEnd;
};

const int maxn=100+2;
Time time[maxn];
Time temp;
int btime, etime;
int num;

void Init()
{
    ///��ʼ��������н�Ŀʱ�����time����
    for(int i=0;i<num;i++)
    {
        scanf("%d %d", &btime, &etime);
        temp.tBegin=btime;
        temp.tEnd=etime;
        time[i]=temp;
    }
}

bool compare(Time a, Time b)
{
    ///�ȽϺ���
    return a.tEnd<b.tEnd;
}

int Process()
{
    ///�жϽ�Ŀ�ɲ����Կ�
    int ans=0, cur=0;
    for(int i=0;i<num;i++)
    {
        if(time[i].tBegin>=cur)
        {
            ans++;
            cur=time[i].tEnd;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d", &num) && num)
    {
        Init();
        sort(time, time+num, compare);
        int ans=Process();
        printf("%d\n", ans);
    }
    return 0;
}
