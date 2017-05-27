#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f;
LL h, w, ans, s1, s2, s3;
int main()
{
    scanf("%I64d%I64d",&h,&w);
    if(h>w)swap(h,w);
    if(h%3==0||w%3==0)printf("0\n");
    else
    {
        ans=INF;
        for(int i=1;i<=w/2+1;i++)   //Èý·Öh
        {
            s1=h*i;
            s2=h*((w-i)/2);
            s3=h*((w-i)-(w-i)/2);
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        for(int i=1;i<=h/2+1;i++)
        {
            s1=w*i;
            s2=(h-i)*(w/2);
            s3=(h-i)*(w-w/2);
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        for(int i=1;i<=w/2+1;i++)
        {
            s1=h*i;
            s2=(h/2)*(w-i);
            s3=(h-h/2)*(w-i);
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
