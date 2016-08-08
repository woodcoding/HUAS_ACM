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
{///第一次排序，按照题目数，时间来排序
    return (a.num>b.num||a.num==b.num&&a.t<b.t);
}

bool cmp2(Time a, Time b)
{///第二次排序，按照输入的顺序来排序
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
        sort(stu, stu+n, cmp1);     //题目时间排序
        for(i=1;i<=4;i++){if(c[i]!=1)c[i]/=2;}    //取前一半的人数
        for(i=0;i<n;i++)
        {///给出成绩
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
        sort(stu, stu+n, cmp2);     //顺序排序
        for(i=0;i<n;i++)printf("%d\n", stu[i].gd);
        printf("\n");
    }
    return 0;
}
