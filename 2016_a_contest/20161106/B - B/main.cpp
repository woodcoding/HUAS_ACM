#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 505
int step[MAX];

int main()
{
    int n, k, a, b, cnt=0;
    while(~scanf("%d %d", &n, &k))
    {
        cnt = 0;
        for(int i=0; i<n; i++)scanf("%d", &step[i]);
        for(int i=1; i<n; i++)
        {
            a = step[i-1];
            b = step[i];
            if(a+b<k)
            {
                cnt+=k-a-b;
                step[i]+=k-a-b;
            }
        }
        printf("%d\n", cnt);
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d", step[i]);
        }
        printf("\n");
    }
    return 0;
}
