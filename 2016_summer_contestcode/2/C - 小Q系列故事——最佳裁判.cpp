#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, ans;
double grade[20], allg, ming, maxg, aveg, space;

int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        maxg=0;
        ming=10;
        allg=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf", &grade[i]);
            allg+=grade[i];
            maxg=maxg>grade[i]?maxg:grade[i];
            ming=ming<grade[i]?ming:grade[i];
        }
        aveg=(allg-maxg-ming)/(n-2);
        space=20;
        //printf("allg=%.1lf maxg=%.1lf ming=%.1lf aveg=%.1lf\n", allg, maxg, ming, aveg);
        for(int j=0;j<n;j++)
        {
            if(abs(grade[j]-aveg)<space)
            {
                ans=j+1;
                space=abs(grade[j]-aveg);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
