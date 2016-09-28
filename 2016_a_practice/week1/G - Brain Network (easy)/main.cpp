#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 1000+10
struct Node{
	int u,v;
}node[MAX];

int n,m,ok;
int p[MAX];

int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);   //寻找父级+路径压缩
}

int check(){
	for (int i=0;i<m;i++){
		int u=node[i].u;
		int v=node[i].v;
		int pu=find(u);
		int pv=find(v);
		if (pu!=pv){
			for (int i=1;i<=n;i++)
			{
				if (p[i]==pv)p[i]=pu;       //结合
			}
		}
		else return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if (i==find(i))cnt++;       //找根节点数
	}
	if (cnt==1)return 1;
	else return 0;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for (int i=0;i<m;i++)scanf("%d%d",&node[i].u,&node[i].v);   //初始化
		for (int i=1;i<=n;i++)p[i]=i;
			if (check())ok=1;
			else ok=0;
		if (ok)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
