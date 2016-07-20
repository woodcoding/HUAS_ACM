#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

struct Node
{
    int left;
    int right;
    int value;
};

const int maxn=50000+1;
const int maxm=65536*2;
int flower[maxn];
Node treeNode[maxm];
int T, N;
int Queryans;

void BuildTree(int index, int left, int right)
{
    treeNode[index].value=0;        //每个节点初始化为0
    treeNode[index].left=left;      //左区间
    treeNode[index].right=right;    //右区间
    if(left==right)                 //如果是叶子节点则赋值并且把节点的下标放到flower数组
    {
        int treeValue;
        scanf("%d", &treeValue);
        treeNode[index].value=treeValue;
        flower[left]=index;
        return;
    }
    BuildTree(index<<1, left, (left+right)>>1);     //新建下一个左节点
    BuildTree((index<<1)+1, ((left+right)>>1)+1, right);    //新建下一个右节点
}

void Update(int inode)
{
    if(inode==1)return;     //如果更新到了根节点则返回
    int fnode=inode>>1;     //inode除以2得到父节点
    int a=treeNode[fnode<<1].value;     //父节点的左子节点的值
    int b=treeNode[(fnode<<1)+1].value; //父节点的右子节点的值
    treeNode[fnode].value=a+b;          //更新父节点的值
    Update(fnode);                      //递归更新上一级
}

void ToQuery(int i, int qleft, int qright)
{
    if(treeNode[i].left==qleft&&treeNode[i].right==qright)  //如果找到符合区间
    {
        Queryans+=treeNode[i].value;        //结果要增加
        return;
    }
    i = i<<1;                           //左子节点
    if(qleft<=treeNode[i].right)        //左区间有值
    {
        if(qright<=treeNode[i].right)ToQuery(i, qleft, qright); //完全在左区间
        else ToQuery(i, qleft, treeNode[i].right);              //部分在左区间
    }
    i+=1;                               //右子节点
    if(qright>=treeNode[i].left)        //右边区间有值
    {
        if(qleft>=treeNode[i].left)ToQuery(i, qleft, qright);     //完全在右区间
        else ToQuery(i, treeNode[i].left, qright);
    }
}

void Init()
{
    scanf("%d", &N);
    BuildTree(1, 1, N);
    for(int i=1;i<=N;i++)Update(flower[i]);
    //for(int i=1;i<=N;i++)cout<<treeNode[flower[i]].value<<" ";
    //cout<<endl;
}

void Query(int qcoma, int qcomb)
{
    Queryans=0;
    ToQuery(1, qcoma, qcomb);
    printf("%d\n", Queryans);
}

void Add(int acoma, int acomb)
{
    treeNode[flower[acoma]].value+=acomb;
    Update(flower[acoma]);
}

void Sub(int scoma, int scomb)
{
    treeNode[flower[scoma]].value-=scomb;
    Update(flower[scoma]);
}

bool Command(char *ccommand)
{
    int coma, comb;
    if(ccommand[0]=='E')return 0;
    else if(ccommand[0]=='Q')
    {
        scanf("%d %d", &coma, &comb);
        Query(coma, comb);
    }
    else if(ccommand[0]=='A')
    {
        scanf("%d %d", &coma, &comb);
        Add(coma, comb);
    }
    else if(ccommand[0]=='S')
    {
        scanf("%d %d", &coma, &comb);
        Sub(coma, comb);
    }
    return 1;
}

int main()
{
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
    {
        Init();
        printf("Case %d:\n", i);
        while(1)
        {
            char command[10];
            scanf("%s", &command);
            if(!Command(command))break;
        }
    }
    return 0;
}
