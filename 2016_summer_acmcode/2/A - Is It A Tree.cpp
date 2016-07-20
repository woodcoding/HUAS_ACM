#include <iostream>
#include <memory.h>
using namespace std;

const int maxn=10000+10;
int nodeL[maxn], nodeR[maxn];
int nleft, nright, nmax;
int edge, node;
int icase=0;
bool isTree;

void Init()
{
    memset(nodeL, 0, sizeof(nodeL));
    memset(nodeR, 0, sizeof(nodeR));
    edge=0;
    node=0;
    nmax=maxn-1;
}

bool CountNode()
{
    for(int i=0;i<=nmax;i++)
    {
        if(nodeR[i]>1)return false;
        if(nodeL[i] || nodeR[i])node++;
    }
    return true;
}

int main()
{
    Init();
    while(cin>>nleft>>nright && nleft!=-1 && nright!=-1)    //判断输入是否结束
    {
        if(nleft || nright)   //如果输入的值不是0则放入数组统计
        {
            nodeL[nleft]++;
            nodeR[nright]++;
            edge++;
            nmax=nmax>nleft?nmax:nleft;
            nmax=nmax>nright?nmax:nright;
        }
        else               //输入的值为0则进行运算并在之后清空操作
        {
            if(CountNode() && node==edge+1)isTree=true;
            else isTree=false;
            if(!edge)isTree=true;
            if(isTree)cout<<"Case "<<++icase<<" is a tree."<<endl;
            else cout<<"Case "<<++icase<<" is not a tree."<<endl;
            Init();
        }
    }
    return 0;
};
