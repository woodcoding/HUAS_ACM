#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, i, x, isTrue;
stack<int> railsin;     //ջ�� ��������ʱ��ת
queue<int> railsout;    //�жӣ������û�����
int Init()
{
    while(!railsin.empty())railsin.pop();       //��ʼ����ղ���
    while(!railsout.empty())railsout.pop();
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(!x)return 0;     //���0�� ����0��ʹ����ѭ���˳�
        railsout.push(x);
    }
    isTrue=1;
    return 1;
}
void Judge()
{
    int inX=1;
    //�жӺ�ջͬʱģ�����
    while(!railsout.empty())
    {
        if(inX==railsout.front())
        {
            railsout.pop();
            inX++;
        }
        else if(!railsin.empty() && railsin.top()==railsout.front())
        {
            railsin.pop();
            railsout.pop();
        }
        else if(inX<n)
        {
            railsin.push(inX++);
        }
        else
        {
            isTrue = 0;
            break;
        }
    }
}
int main()
{
    while(cin>>n && n)                  //�޸��������˳���bug
    {
        while(1)
        {
            if(!Init()){cout<<endl;break;}  //�޸��������˳���bug
            Judge();
            if(isTrue)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
