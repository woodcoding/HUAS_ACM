#include<iostream>
using namespace std;

#define MAX 5001
int n, x, i, count1, final;
int Soldiers[MAX];

//��ʼ������
void Init()
{
	for(i=1;i<=x;i++)Soldiers[i]=i;
	for(i=5000;i>x;i--)Soldiers[i]=0;
}

//��������
void Process()
{
	int flag;
	flag=0;
	//����2�ţ�ɾ��
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

	//����3�ţ�ɾ��
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

//�������
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


//��Ŀ
/*
Description
ĳ���ӽ����±�����ѵ�������±���һ��ʼ��˳�����α�ţ����ų�һ�к�ӣ�ѵ���Ĺ������£���ͷ��ʼһ�������������������ĳ��У�ʣ�µ���С��ŷ���£���ٴ�ͷ��ʼ����һ�������������������ĳ��У�ʣ�µ���С��ŷ���£��������ͷ��ʼ����һ�����������������Ժ��ͷ��ʼ��������һ����������һ��������ֱ��ʣ�µ���������������Ϊֹ�� 
 
Input
�����ж�����������飬��һ��Ϊ����N������ΪN���±��������±�����������5000�� 
 
Output
����N�У��ֱ��Ӧ������±�������ÿ�����ʣ�µ��±�����ı�ţ����֮����һ���ո� 
 
Sample Input
2
20
40 
 
Sample Output
1 7 19
1 19 37 
*/