#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=110;
const int maxl=80;
struct String{
    char str[maxl];
    bool operator<(const String & cmp) const{
        return strcmp(str,cmp.str)<0;
    }
}str[maxn];
int n, len, w, h;

int main()
{
    while(~scanf("%d", &n)){
        len=0;
        for(int i=0;i<n;i++){
            scanf("%s", &str[i].str);
            len=max(len, int(strlen(str[i].str))+2);
        }
        sort(str, str+n);
        w=max(1, 60/len);
        h=1;
        while(h*w<n)h++;
        for(int i=0;i<60;i++)putchar('-');
        printf("\n");int cnt=0;
        for(int i=0;i<h;i++){
            int now=i;
            while(now<n){
                printf("%s", str[now].str);
                cnt++;
                int tl=len-strlen(str[now].str);
                if(cnt<n)for(int i=0;i<tl;i++)printf(" ");
                now+=h;
            }
            printf("\n");
        }
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
char s[10000][500];
int main()
{
    char temp[500];
    int n,i,j,k,len,lmax,line,column,num,sum;
    while (scanf("%d",&n)!=EOF)
    {
        getchar();
        lmax=0;
        for (i=1; i<=n; i++)
        {
            scanf("%s",&s[i]);
            len=strlen(s[i]);
            if (len>lmax) lmax=len;
        }
        for (i=1; i<n; i++)
            for (j=i+1; j<=n; j++)
                if (strcmp(s[i],s[j])>0)
                {
                    strcpy(temp,s[i]);
                    strcpy(s[i],s[j]);
                    strcpy(s[j],temp);
                }
        printf("------------------------------------------------------------\n");
        line=60/(lmax+2);
        if (line==0) line=1;
        column=n/line;
        if (n%line!=0) ++column;
        sum=0;
        for (j=0; j<column; j++)
        {
            for (i=1; i<=line; i++)
            {
                num=column*i-column+1+j;
                if (num<=n)
                {
                    ++sum;
                    printf("%s",s[num]);
                    len=strlen(s[num]);
                    if (sum<n)
                        for (k=len; k<lmax+2; k++)
                            printf(" ");
                }
            }
            printf("*\n");
        }
    }
    return 0;
}
*/
