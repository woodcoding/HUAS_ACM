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
    treeNode[index].value=0;        //ÿ���ڵ��ʼ��Ϊ0
    treeNode[index].left=left;      //������
    treeNode[index].right=right;    //������
    if(left==right)                 //�����Ҷ�ӽڵ���ֵ���Ұѽڵ���±�ŵ�flower����
    {
        int treeValue;
        scanf("%d", &treeValue);
        treeNode[index].value=treeValue;
        flower[left]=index;
        return;
    }
    BuildTree(index<<1, left, (left+right)>>1);     //�½���һ����ڵ�
    BuildTree((index<<1)+1, ((left+right)>>1)+1, right);    //�½���һ���ҽڵ�
}

void Update(int inode)
{
    if(inode==1)return;     //������µ��˸��ڵ��򷵻�
    int fnode=inode>>1;     //inode����2�õ����ڵ�
    int a=treeNode[fnode<<1].value;     //���ڵ�����ӽڵ��ֵ
    int b=treeNode[(fnode<<1)+1].value; //���ڵ�����ӽڵ��ֵ
    treeNode[fnode].value=a+b;          //���¸��ڵ��ֵ
    Update(fnode);                      //�ݹ������һ��
}

void ToQuery(int i, int qleft, int qright)
{
    if(treeNode[i].left==qleft&&treeNode[i].right==qright)  //����ҵ���������
    {
        Queryans+=treeNode[i].value;        //���Ҫ����
        return;
    }
    i = i<<1;                           //���ӽڵ�
    if(qleft<=treeNode[i].right)        //��������ֵ
    {
        if(qright<=treeNode[i].right)ToQuery(i, qleft, qright); //��ȫ��������
        else ToQuery(i, qleft, treeNode[i].right);              //������������
    }
    i+=1;                               //���ӽڵ�
    if(qright>=treeNode[i].left)        //�ұ�������ֵ
    {
        if(qleft>=treeNode[i].left)ToQuery(i, qleft, qright);     //��ȫ��������
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
