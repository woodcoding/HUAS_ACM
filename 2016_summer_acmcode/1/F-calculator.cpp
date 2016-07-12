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
    //���յ�һ���ַ���
    while(cin>>a)
    {
        sum = 0;
        while(!mystack.empty())mystack.pop();   //���ջ
        c = getchar();  //���տո������ĩ�ַ�
        if(a==0 && c=='\n')break;
        mystack.push(a);    //a��ջ
        c = getchar();      //���������
        while(cin>>b)
        {
            //��������
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
            c = getchar();  //���տո�����ļ�β
            if(c == '\n')break;
            c = getchar();  //���������
            getchar();      //���տո�
        }
        //���
        while(!mystack.empty())
        {
            sum+=mystack.top();
            mystack.pop();
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}
