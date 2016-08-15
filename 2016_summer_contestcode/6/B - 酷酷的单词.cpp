#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[28];
int n, cnt, len;
char str[35];

int main()
{
    int cas=1;
    while(scanf("%d", &n)!=EOF)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            memset(num, 0, sizeof(num));
            bool flag=1;
            scanf("%s", &str);
            len=strlen(str);
            if(len==1)continue;
            for(int j=0;j<len;j++)num[str[j]-'a'+1]++;
            sort(num+1,num+1+26);
            for(int j=1;j<=26;j++)
            {
                if(num[j]!=0&&num[j]==num[j+1]){flag=0;break;}
            }
            cnt+=flag;
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
    return 0;
}
