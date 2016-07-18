#include <iostream>
#include <algorithm>

using namespace std;

class Enemy
{
public:
    int  dps;
    int  hp;
    Enemy(int edps=0, int ehp=0):dps(edps),hp(ehp){}
};

const int maxn=20;
int n;
int myhp, alldps;
Enemy enemy[maxn];

void Init()
{
    int dpsi, hpi;
    myhp=0;
    alldps=0;
    for(int i=0;i<n;i++)
    {
        cin>>dpsi>>hpi;
        enemy[i]=Enemy(dpsi, hpi);  //敌人对象化
        alldps+=dpsi;               //计算所有敌人的伤害值
    }
}

bool compare(Enemy a, Enemy b)
{
    ///优先攻击血量少攻击高的英雄
    return (double)a.dps/(double)a.hp>(double)b.dps/(double)b.hp;
}

void Attack()
{
    ///攻击英雄，按照compare的顺序
    for(int ai=0;ai<n;ai++)
    {
        myhp+=enemy[ai].hp*alldps;    //攻击敌人
        alldps-=enemy[ai].dps;      //敌人死亡
    }
}

int main()
{
    while(cin>>n)
    {
        Init();
        sort(enemy, enemy+n, compare);
        Attack();
        cout<<myhp<<endl;
    }
    return 0;
}
