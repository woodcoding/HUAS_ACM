#include<iostream>
#include<cstdio>
#include<stack>
#include <iomanip>
using namespace std;
stack<double> mystack;
int main()
{
    double a, b, sum;
    char c;
    //接收第一个字符串
    while(cin>>a)
    {
        sum = 0;
        while(!mystack.empty())mystack.pop();   //清空栈
        c = getchar();  //接收空格或者行末字符
        if(a==0 && c=='\n')break;
        mystack.push(a);    //a入栈
        c = getchar();      //接收运算符
        while(cin>>b)
        {
            //基本运算
            switch(c)
            {
            case '*':
                a = mystack.top();
                mystack.pop();
                mystack.push(a*b);
                break;
            case '/':
                a = mystack.top();
                mystack.pop();
                mystack.push(a/b);
                break;
            case '+':
                mystack.push(b);
                break;
            case '-':
                mystack.push(-b);
                break;
            }
            c = getchar();  //接收空格或者文件尾
            if(c == '\n')break;
            c = getchar();  //接收运算符
            getchar();      //接收空格
        }
        //求和
        while(!mystack.empty())
        {
            sum+=mystack.top();
            mystack.pop();
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}
