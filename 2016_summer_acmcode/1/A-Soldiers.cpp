#include<iostream>
using namespace std;

#define MAX 5001
int n, x, i, count1, final;
int Soldiers[MAX];

//初始化数组
void Init()
{
	for(i=1;i<=x;i++)Soldiers[i]=i;
	for(i=5000;i>x;i--)Soldiers[i]=0;
}

//处理数组
void Process()
{
	int flag;
	flag=0;
	//报数2号，删除
	for(i=1;i<=final;i++)
	{
		while(Soldiers[i])
		{
			flag++;
			//cout<<"flag=="<<flag<<"\t";
			//cout<<"i=="<<i<<"\n";
			if(flag==2)
			{
				//cout<<Soldiers[i]<<"\n";
				Soldiers[i]=0;
				count1--;
				flag=0;
			}
			break;
		}
	}
	if(count1<=3)return;
	flag=0;

	//报数3号，删除
	for(i=1;i<=final;i++)
	{
		while(Soldiers[i])
		{
			flag++;
			//cout<<"flag=="<<flag<<"\t";
			//cout<<"i=="<<i<<"\n";
			if(flag==3)
			{
				//cout<<Soldiers[i]<<"\n";
				Soldiers[i]=0;
				count1--;
				flag=0;
			}
			break;
		}
	}
	if(count1<=3)return;
}

//输出操作
void Print()
{
	for(i=1;i<=final;i++)
	{
		while(Soldiers[i])
		{
			if(i!=1)cout<<" ";
			cout<<Soldiers[i];
			break;
		}
	}
	cout<<endl;
}

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>x;
		count1=x;
		final=x;
		Init();
		while(count1>3)Process();
		Print();
	}
	return 0;
}


//题目
/*
Description
某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队，训练的规则如下：从头开始一至二报数，凡报到二的出列，剩下的向小序号方向靠拢，再从头开始进行一至三报数，凡报到三的出列，剩下的向小序号方向靠拢，继续从头开始进行一至二报数。。。，以后从头开始轮流进行一至二报数、一至三报数直到剩下的人数不超过三人为止。 
 
Input
本题有多个测试数据组，第一行为组数N，接着为N行新兵人数，新兵人数不超过5000。 
 
Output
共有N行，分别对应输入的新兵人数，每行输出剩下的新兵最初的编号，编号之间有一个空格。 
 
Sample Input
2
20
40 
 
Sample Output
1 7 19
1 19 37 
*/