#include <iostream>
//#include <cstdio>
using namespace std;
const int maxn=30000;
int n, m, num, master, people;
int studata[maxn];

void Init()
{
    ///初始化上级为自己
    for(int i=0;i<n;i++)studata[i]=i;
}

int Find(int man)
{
    int fmaster=man;
    while(studata[fmaster]!=fmaster)fmaster=studata[fmaster];
    int fman=man, tman;
    while(studata[fman]!=fmaster)
    {
        tman=studata[fman];
        studata[fman]=fmaster;
        fman=tman;
    }
    return fmaster;
}

int Find2(int man)
{
    int fmaster=man;
    while(studata[fmaster]!=fmaster)fmaster=studata[fmaster];
    return fmaster;
}

void Join(int remaster, int repeople)
{
    int jmaster=Find(remaster);
    int jpeople=Find(repeople);
    //cout<<"---->jmaster:"<<jmaster<<" jpeople:"<<jpeople<<endl;
    if(jmaster!=jpeople)
    {
        studata[jpeople]=jmaster;
    }
}

void Fix()
{
    if(studata[0]==0)
    {   //修复0在顶端的三级树的情况
        for(int i=0;i<n;i++)if(studata[i]==0){studata[0]=studata[i];break;}
    }
    if(studata[0]!=0 && studata[studata[0]]==studata[0])
    {   //修复0在二级的三级树的情况
        studata[studata[0]]=0;
        studata[0]=0;
    }
    else if(studata[studata[studata[0]]]==studata[studata[0]])
    {   //修复0在三级的三级树的情况
        studata[studata[studata[0]]]=studata[studata[0]];
        studata[studata[0]]=studata[studata[0]];
    }
}

void Print()
{
    //Fix();
    //for(int i=0;i<n;i++)cout<<"<"<<i<<","<<studata[i]<<">  ";
    int gg=studata[0];
    int ans=0;
    for(int i=0;i<n;i++)if(studata[i]==gg)ans++;
    cout<<ans<<endl;
}

void Print2()
{
    int pmaster=Find2(0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(Find(studata[i])==pmaster)ans++;
        //cout<<"<"<<i<<","<<Find(studata[i])<<">  ";
    }
    cout<<ans<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(cin>>n>>m && n+m)
    {
        Init();
        while(m--)
        {
            cin>>num>>master;
            //cout<<"------>num:"<<num<<" master:"<<master<<endl;
            for(int i=0;i<num-1;i++)
            {
                cin>>people;
                //cout<<"------>master:"<<master<<" people:"<<people<<endl;
                Join(master, people);
            }
        }
        Print2();
    }
    return 0;
}
