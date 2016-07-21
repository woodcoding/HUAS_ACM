#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

struct Node
{
    int left;
    int right;
    int value;
};

const int maxn=2000000;     //数组开小了会TLE

Node treeNode[maxn*2];
int student[maxn];
int N, M;
char command[2];
int coma, comb;
int maxAns=0;

void BuildTree(int index, int left, int right)
{
    treeNode[index].left=left;
    treeNode[index].right=right;
    treeNode[index].value=0;
    if(left==right)
    {
        student[left]=index;
        return;
    }
    int mid=(left+right)>>1;
    BuildTree(index<<1, left, mid);
    BuildTree((index<<1)+1, mid+1, right);
}

void Update(int inode)
{
    if(inode==1)return;
    int fnode=inode>>1;
    int a=treeNode[fnode<<1].value;
    int b=treeNode[(fnode<<1)+1].value;
    treeNode[fnode].value=a>b?a:b;
    Update(fnode);
}

void Search(int index, int left, int right)
{
    if(treeNode[index].left==left&&treeNode[index].right==right)
    {
        maxAns=maxAns>treeNode[index].value?maxAns:treeNode[index].value;
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

void Init()
{
    BuildTree(1, 1, N);
    int orgGrade;
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &orgGrade);
        treeNode[student[i]].value=orgGrade;
        Update(student[i]);
    }
}

void Command()
{
    if(command[0]=='Q')
    {
        maxAns=0;
        Search(1, coma, comb);
        printf("%d\n", maxAns);
    }
    if(command[0]=='U')
    {
        treeNode[student[coma]].value=comb;
        Update(student[coma]);
    }
}

int main()
{
    while(scanf("%d %d", &N, &M)!=EOF)
    {
        Init();
        for(int i=1;i<=M;i++)
        {
            maxAns=1000000;
            scanf("%s %d %d", &command, &coma, &comb);     //输入这里有个坑，%c会错位
            Command();
        }
    }
    return 0;
}
