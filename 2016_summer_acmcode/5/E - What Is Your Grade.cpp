#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int maxn=110;

struct Time
{
    int num,t,no,gd;
}stu[maxn];

int n, i, c[6], h, m, s;

bool cmp1(Time a, Time b)
{///��һ�����򣬰�����Ŀ����ʱ��������
    return (a.num>b.num||a.num==b.num&&a.t<b.t);
}

bool cmp2(Time a, Time b)
{///�ڶ������򣬰��������˳��������
    return a.no<b.no;
}

int main()
{
    while(~scanf("%d", &n) && n>=0)
    {
        memset(c, 0, sizeof(c));
        for(i=0;i<n;i++)
        {
            scanf("%d %d:%d:%d", &stu[i].num, &h, &m, &s);
            stu[i].t=h*3600+m*60+s;
            stu[i].no=i;
            c[stu[i].num]++;
        }
        sort(stu, stu+n, cmp1);     //��Ŀʱ������
        for(i=1;i<=4;i++){if(c[i]!=1)c[i]/=2;}    //ȡǰһ�������
        for(i=0;i<n;i++)
        {///�����ɼ�
            switch(stu[i].num)
            {
            case 5:
                stu[i].gd=100;break;
            case 4:
                if(c[4]==0)stu[i].gd=90;
                else {stu[i].gd=95;c[4]--;}
                break;
            case 3:
                if(c[3]==0)stu[i].gd=80;
                else {stu[i].gd=85;c[3]--;}
                break;
            case 2:
                if(c[2]==0)stu[i].gd=70;
                else {stu[i].gd=75;c[2]--;}
                break;
            case 1:
                if(c[1]==0)stu[i].gd=60;
                else {stu[i].gd=65;c[1]--;}
                break;
            case 0:
                stu[i].gd=50;break;
            }
        }
        sort(stu, stu+n, cmp2);     //˳������
        for(i=0;i<n;i++)printf("%d\n", stu[i].gd);
        printf("\n");
    }
    return 0;
}
