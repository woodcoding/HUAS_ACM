#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10005
int res[MAX],len[MAX];
int n, m, maxlen, l;
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &res[i]);
            len[i]=1;
        }
        for(int i=n-1; i>=1; i--) //从后往前记录当前开始的LIS
        {
            for(int j=n; j>i; j--)
            {
                if(res[j]>res[i])len[i]=max(len[i], len[j]+1);
            }
        }
        maxlen=0;
        for(int i=1; i<=n; i++)maxlen=max(maxlen, len[i]);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d", &l);
            if(l>maxlen)printf("Impossible");
            else
            {
                int t=-1, flag=0;
                for(int i=1; i<=n; i++)
                {
                    if(len[i]>=l && res[i]>t){
                        if(flag)printf(" ");
                        printf("%d", res[i]);
                        l--;
                        t = res[i];
                        flag=1;
                    }
                    if(!l)break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}