#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 4005

int a[MAX], b[MAX], c[MAX], d[MAX];
int ab[MAX*MAX], cd[MAX*MAX];
int n, ans;

int search_num(int x){
    int l=0,r=n*n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(cd[mid]==x){
            int cnt=0, pos=mid;
            while(pos>=0&&cd[pos--]==x)cnt++;
            pos=mid+1;
            while(pos<n*n&&cd[pos++]==x)cnt++;
            return cnt;
        }
        else if(cd[mid]<x)l=mid+1;
        else r=mid-1;
    }
    return 0;
}

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++)scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ab[i*n+j]=a[i]+b[j];
                cd[i*n+j]=-(c[i]+d[j]);
            }
        }
        sort(ab, ab+n*n);
        sort(cd, cd+n*n);
        for(int i=0;i<n*n;i++)ans+=search_num(ab[i]);
        printf("%d\n", ans);
    }
    return 0;
}
