#include <iostream>
#define MAX 12

using namespace std;
int n, x, sum, emp[MAX], cur, res[MAX];

void NEmpress(int cur)
{
    if(cur==n+1)sum++;      //������һ��������ϣ�������1
    else
    {
        for(int i=1;i<=n;i++)
        {
            int isTrue = 1;     //Ĭ�Ͽ���ͨ��
            emp[cur]=i;         //��ǰ�еĵ�i�з��ûʺ�
            for(int j=1;j<cur;j++)
            {
                if(j-emp[j]==cur-emp[cur] || emp[cur]==emp[j] || j+emp[j]==cur+emp[cur])
                {
                    isTrue=0;       //����г�ͻ���˳���ǰ�ݹ�
                    break;
                }
            }
            if(isTrue)NEmpress(cur+1);  //������һ������
        }
    }
}

int main()
{
    for(n=1;n<=10;n++){sum=0;NEmpress(1);res[n]=sum;}
    while(cin>>x && x)
    {
        cout<<res[x]<<endl;
    }
    return 0;
}
