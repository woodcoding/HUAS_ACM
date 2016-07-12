#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, i, x, isTrue;
stack<int> railsin;     //栈， 用用于临时中转
queue<int> railsout;    //列队，用于用户输入
int Init()
{
    while(!railsin.empty())railsin.pop();       //初始化清空操作
    while(!railsout.empty())railsout.pop();
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(!x)return 0;     //如果0， 返回0，使本次循环退出
        railsout.push(x);
    }
    isTrue=1;
    return 1;
}
void Judge()
{
    int inX=1;
    //列队和栈同时模拟过程
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
    while(cin>>n && n)                  //修复程序不能退出的bug
    {
        while(1)
        {
            if(!Init()){cout<<endl;break;}  //修复程序不能退出的bug
            Judge();
            if(isTrue)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
