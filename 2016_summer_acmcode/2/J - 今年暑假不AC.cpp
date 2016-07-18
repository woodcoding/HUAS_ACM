#include <iostream>

using namespace std;
class Time
{
public:
    int tBegin;
    int tEnd;
    Time(int tb=0, int te=0):tBegin(tb), tEnd(te){}
};
const int maxn=100+1;
int n, tn;
Time time[maxn];

void Init()
{
    ///��ʼ������ʱ���
    int ta, tb;
    for(int i=1;i<=n;i++)
    {
        cin>>ta>>tb;
        time[i]=Time(ta, tb);
    }
}

void Sort(int left, int right)
{
    ///�����������
    int i, j;
    Time ttime, xtemp;
    if(left>right)return;
    xtemp=time[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(time[j].tEnd>=xtemp.tEnd && i<j)j--;  //�ȴ��ұ��ң���ǳ���Ҫ
        while(time[i].tEnd<=xtemp.tEnd && i<j)i++;
        if(i<j){ttime=time[i];time[i]=time[j];time[j]=ttime;}
    }
    time[left]=time[i];
    time[i]=xtemp;
    Sort(left, i-1);
    Sort(i+1, right);
    return;
}

void Print()
{
    ///�жϺ����
    int ans=0;
    int cur=0;
    for(int pi=1;pi<=n;pi++)
    {
        if(time[pi].tBegin>=cur){ans++;cur=time[pi].tEnd;}
    }
    cout<<ans<<endl;
}

class TestCase
{
public:
    void TestSort();
};
void TestCase::TestSort()
{
    ///���Կ��ŵĺ���
    for(int ti=1;ti<=n;ti++)cout<<"<"<<time[ti].tBegin<<","<<time[ti].tEnd<<">"<<endl;
}

int main()
{
    while(cin>>n && n)
    {
        TestCase test;
        Init();
        //test.TestSort();
        Sort(1, n);
        //test.TestSort();
        Print();
    }
    return 0;
}
