#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int left;
    int right;
    long long value, inc;
};

const int maxn=1000000;
Node treeNode[maxn];
int n, q;
char command[2];
int coma, comb, comc;
long long QueryAns=0;

void BuildTree(int index, int left, int right)
{
    ///新建树
    treeNode[index].left=left;
    treeNode[index].right=right;
    treeNode[index].value=0;
    treeNode[index].inc=0;
    if(left==right)
    {
        long long value;
        scanf("%lld", &value);
        treeNode[index].value=value;    //更新叶子节点
        return;
    }
    int mid=(left+right)>>1;
    BuildTree(index<<1,left,mid);
    BuildTree((index<<1)+1,mid+1,right);
    treeNode[index].value+=treeNode[index<<1].value+treeNode[(index<<1)+1].value;   //更新父节点
}

void Update(int left, int right, int value, int index)
{
   if(treeNode[index].left <= left && treeNode[index].right >= right)
    {
       treeNode[index].value += (right-left+1)*value;
       if(treeNode[index].left == left && treeNode[index].right == right)
            treeNode[index].inc += value;   //lazy思想，暂存，不继续更新
       else
        { //不是恰好符合的区间，继续更新
           int mid=(treeNode[index].left+treeNode[index].right)/2;
           if(right <= mid)Update(left,right,value,index*2);
           else if(left>mid)Update(left,right,value,index*2+1);
           else
           {
              Update(left,mid,value,2*index);
              Update(mid+1,right,value,2*index+1);
           }
        }
   }
}
void Query(int left, int right, int index)
{
   int mid=(treeNode[index].left+treeNode[index].right)/2;
   if(left == treeNode[index].left && right == treeNode[index].right)
    {QueryAns += treeNode[index].value;}
   else if(left>mid)
    {
        QueryAns += treeNode[index].inc*(right-left+1);     //暂存区有值就加上
        Query(left,right,2*index+1);
    }
   else if(right<=mid)
    {
        QueryAns += treeNode[index].inc*(right-left+1);
        Query(left,right,2*index);
    }
   else
    {
        QueryAns += treeNode[index].inc*(right-left+1);
        Query(left,mid,2*index);
        Query(mid+1,right,2*index+1);
    }
}

int main()
{
    while(scanf("%d%d", &n, &q)!=EOF && n && q)
    {
        BuildTree(1, 1, n);
        for(int i=1;i<=q;i++)
        {
            scanf("%s", &command);
            if(command[0]=='C')
            {
                if(coma>comb)swap(coma, comb);
                scanf("%d%d%d", &coma, &comb, &comc);
                Update(coma, comb, comc, 1);
            }
            if(command[0]=='Q')
            {
                QueryAns=0;
                scanf("%d%d", &coma, &comb);
                Query(coma, comb, 1);
                printf("%lld\n", QueryAns);
            }
        }
    }
    return 0;
}
