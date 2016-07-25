#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Village
{
    int a;
    int b;
    int len;        //������ׯ�ľ���
};

const int maxn=5000;        //���Ǹ�����������Ŀ�����Ǵ�ׯ����Ŀ
Village village[maxn];
int flag[maxn];
int a, b, len, i, j, n, num;

void Init()
{
    num=n*(n-1)/2;
    for(i=1;i<=num;i++)     //��ó�ʼ����
        scanf("%d%d%d", &village[i].a, &village[i].b, &village[i].len);
    for(i=1;i<=n;i++)flag[i]=i;     //��ʼ�����ڵ�Ϊ�Լ�
}

bool cmp(Village cmpa, Village cmpb)
{
    return cmpa.len<cmpb.len;       //�����С��������
}

int Find(int x)
{   //�Ҹ��ڵ�
    if(flag[x]==x)return x;
    flag[x]=Find(flag[x]);
    return flag[x];
}

int Process()
{
    int sum=0;
    for(i=1;i<=num;i++)
    {
        int fa=Find(village[i].a);
        int fb=Find(village[i].b);
        if(fa==fb)continue;
        else
        {
            sum+=village[i].len;        //���ڵ㲻ͬ���������
            if(fa>fb)       //����С�ڶ��У�����ͬһ������
                flag[fb]=fa;
            else
                flag[fa]=fb;
        }
    }
    return sum;
}

int main()
{
    while(scanf("%d", &n)!=EOF &&n)
    {
        Init();
        sort(village+1, village+1+num, cmp);
        int ans=Process();
        printf("%d\n", ans);
    }
    return 0;
}
