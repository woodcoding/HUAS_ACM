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
        enemy[i]=Enemy(dpsi, hpi);  //���˶���
        alldps+=dpsi;               //�������е��˵��˺�ֵ
    }
}

bool compare(Enemy a, Enemy b)
{
    ///���ȹ���Ѫ���ٹ����ߵ�Ӣ��
    return (double)a.dps/(double)a.hp>(double)b.dps/(double)b.hp;
}

void Attack()
{
    ///����Ӣ�ۣ�����compare��˳��
    for(int ai=0;ai<n;ai++)
    {
        myhp+=enemy[ai].hp*alldps;    //��������
        alldps-=enemy[ai].dps;      //��������
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
