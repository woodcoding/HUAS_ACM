#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int left;
    int right;
    long long value;
};

const int maxn=100000+10;
Node treeNode[maxn*6];
char str[maxn], cht[2];
__int64 res[maxn];
int x, num, tnum;
long long myans;

void Init()
{
    num=1;
    tnum=1;
    while(scanf("%c", &cht))
    {
        if(cht[0]=='\n')break;
        str[num++]=cht[0];
    }
    __int64 t1, t2;
    res[0]=1;
    for(int i=1;i<num;i++)
    {
        t1=str[i];
        t2=(t1-28);
        res[i]=t2;
    }
}
void BuildTree(int index, int left, int right)
{
    treeNode[index].left=left;
    treeNode[index].right=right;
    treeNode[index].value=1;
    if(left==right)
    {
        long long val;
        treeNode[index].value=res[tnum++];
        return;
    }
    int mid=(left+right)>>1;
    BuildTree(index<<1, left, mid);
    BuildTree((index<<1)+1, mid+1, right);
    long long tval;
    tval=treeNode[index<<1].value*treeNode[(index<<1)+1].value;   //更新父节点
    if(tval>=9973)tval%=9973;
    treeNode[index].value=tval;
}

void Search(int index, int left, int right)
{
    if(treeNode[index].left==left&&treeNode[index].right==right)
    {
        myans*=treeNode[index].value;
        if(myans>=9973)myans%=9973;
        return;
    }
    index=index<<1;
    if(left<=treeNode[index].right)  //左区间有涉及
    {
        if(right<=treeNode[index].right)Search(index, left, right); //全部在左区间
        else Search(index, left, treeNode[index].right);
    }
    index+=1;
    if(right>=treeNode[index].left)   //右区间有涉及
    {
        if(left>=treeNode[index].left)Search(index, left, right); //全部在右区间
        else Search(index, treeNode[index].left, right);
    }
}

void Print()
{
    int a, b;
    for(int i=1;i<=x;i++)
    {
        scanf("%d%d", &a, &b);
        myans=1;
        if(a==0)a=1;
        if(b==0)b=1;
        if(a>b){int tt;tt=a;a=b;b=tt;}
        Search(1,a,b);
        printf("%lld\n", myans);
    }
}

int main()
{
    while(~scanf("%d", &x))
    {
        getchar();
        Init();
        BuildTree(1,1,num-1);
        Print();
    }
    return 0;
}
