#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

//坑比题目，还要保证ACGT的顺序

const int maxn=1005;
int n, m, ans, t;
char data[55][maxn];
int cnt[4];
char dna[4]={'A', 'C', 'G', 'T'};

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%s", &data[i]);
        }
        ans=0;
        for(int j=0;j<m;j++){
            memset(cnt, 0, sizeof(cnt));
            for(int i=0;i<n;i++){
                if(data[i][j]=='A')cnt[0]++;
                else if(data[i][j]=='C')cnt[1]++;
                else if(data[i][j]=='G')cnt[2]++;
                else if(data[i][j]=='T')cnt[3]++;
            }
            int tmp=cnt[0], pos=0;
            for(int i=1;i<4;i++){
                if(cnt[i]>tmp){pos=i;tmp=cnt[i];}
            }
            ans+=(n-tmp);
            data[n][j]=dna[pos];
        }
        data[n][m]=0;
        printf("%s\n%d\n", data[n], ans);
    }
    return 0;
}
