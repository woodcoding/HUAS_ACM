#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

int pan[35], pancake[35], flag[105], x=0, now=1;
char c;

void rev(int a, int b)
{
    int len=(b-a+1)/2;
    while(len--)
    {
        int t=pancake[a];
        pancake[a]=pancake[b];
        pancake[b]=t;
        a++;
        b--;
    }
}

int main()
{
    memset(flag, 0, sizeof(flag));
    while(~scanf("%d", &pan[x++]))
    {
        c=getchar();
        flag[pan[x-1]]++;
        if(c=='\n')
        {
            for(int i=1; i<=x; i++)
            {
                pancake[i]=pan[x-i];
                printf("%d", pan[i-1]);
                if(i==x)printf("\n");
                else printf(" ");
            }
            for(int i=100; i>0; i--)
            {
                while(flag[i]--)
                {
                    if(pancake[now]==i){now++;continue;}
                    if(pancake[x]==i)
                    {
                        rev(now, x);
                        printf("%d ", now++);
                    }
                    else
                    {
                        for(int j=now; j<=x; j++)
                        {
                            if(pancake[j]==i)
                            {
                                rev(j, x);
                                rev(now, x);
                                printf("%d %d ", j, now++);
                            }
                        }
                    }
                }
            }
            printf("0\n");
            x=0;
            now=1;
            memset(flag, 0, sizeof(flag));
        }
    }
    return 0;
}
