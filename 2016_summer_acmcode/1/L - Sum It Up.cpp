#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=13;
int sum, n, i, flag;
int res[maxn], ans[maxn];

void dfs(int add, int index, int cur)
{
    ///add�ǵ�ǰ�ĺͣ�index��ԭʼ����ֵ���±꣬cur�ǽ�������±�
    if(add==sum)
    {
        flag=0;
        cout<<ans[0];
        for(i=1;i<cur;i++)cout<<"+"<<ans[i];
        cout<<endl;
        return;
    }
    for(int j=index;j<n;j++)
    {
        if(j==index||res[j]!=res[j-1])
        {///��֤�����ظ�
            ans[cur]=res[j];
            dfs(add+res[j],j+1,cur+1);
        }
    }
}

int main()
{
    while(cin>>sum>>n && sum+n)
    {
        flag=1;
        for(i=0;i<n;i++)cin>>res[i];
        printf("Sums of %d:\n", sum);
        dfs(0, 0, 0);
        if(flag)printf("NONE\n");
    }
    return 0;
}
