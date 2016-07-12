#include <iostream>
#define MAX 12

using namespace std;
int n, x, sum, emp[MAX], cur, res[MAX];

void NEmpress(int cur)
{
    if(cur==n+1)sum++;      //如果最后一行排列完毕，总数加1
    else
    {
        for(int i=1;i<=n;i++)
        {
            int isTrue = 1;     //默认可以通过
            emp[cur]=i;         //当前行的第i列放置皇后
            for(int j=1;j<cur;j++)
            {
                if(j-emp[j]==cur-emp[cur] || emp[cur]==emp[j] || j+emp[j]==cur+emp[cur])
                {
                    isTrue=0;       //如果有冲突，退出当前递归
                    break;
                }
            }
            if(isTrue)NEmpress(cur+1);  //进入下一行排列
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
