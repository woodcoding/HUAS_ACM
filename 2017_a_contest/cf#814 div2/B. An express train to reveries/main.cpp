#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1005;
int a[maxn], b[maxn], ans[maxn], flag[maxn];
int n, f1, f2, cnt;

int main()
{
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        for(int i=1;i<=n;i++)scanf("%d", &b[i]);
        f1=f2=cnt=0;
        memset(flag, 0, sizeof(flag));
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]){
                ans[i]=a[i];
                flag[a[i]]=1;
            }
            else{
                if(f1==0){f1=i;cnt++;}
                else{f2=i;cnt++;}
            }
        }
        if(cnt==0){
            ans[1]=(a[1]+b[1])/2;
            if(ans[1]==a[1])ans[1]++;
            if(ans[1]==b[1])ans[1]++;
            while(flag[ans[1]])ans[1]++;
            while(ans[1]>n||flag[ans[1]])ans[1]--;
        }
        if(cnt==1){
            ans[f1]=(a[f1]+b[f1])/2;
            if(ans[f1]==a[f1])ans[f1]++;
            if(ans[f1]==b[f1])ans[f1]++;
            while(flag[ans[f1]])ans[f1]++;
            while(ans[f1]>n||flag[ans[f1]])ans[f1]--;
        }
        if(cnt==2){
            ans[f1]=b[f1];
            ans[f2]=a[f2];
            if(flag[ans[f1]]||flag[ans[f2]]){
                ans[f1]=a[f1];
                ans[f2]=b[f2];
            }
        }
        for(int i=1;i<=n;i++){
            if(i==n)printf("%d\n", ans[i]);
            else printf("%d ", ans[i]);
        }
    }
    return 0;
}
