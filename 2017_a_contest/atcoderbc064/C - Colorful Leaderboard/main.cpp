#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
int n, a, ans1, ans2, flag[maxn];

int main()
{
    while(~scanf("%d", &n)){
        memset(flag, 0, sizeof(flag));
        while(n--){
            scanf("%d", &a);
            if(a>3199)flag[9]++;
            else if(a>2799)flag[8]++;
            else if(a>2399)flag[7]++;
            else if(a>1999)flag[6]++;
            else if(a>1599)flag[5]++;
            else if(a>1199)flag[4]++;
            else if(a>799)flag[3]++;
            else if(a>399)flag[2]++;
            else flag[1]++;
        }
        ans1=ans2=0;
        for(int i=1;i<9;i++){
            if(flag[i])ans1++;
        }
        ans2=ans1+flag[9];
        if(ans1==0)ans1=1;
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
