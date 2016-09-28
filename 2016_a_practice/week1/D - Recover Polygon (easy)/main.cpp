#include <iostream>
#include <cstdio>
#define MAX 100
using namespace std;

int n;
int x1,y1,x2,y2;
char omap[MAX][MAX];

bool check(){
    int i, j;
    if(omap[x1][y1]!='1'||omap[x1][y2]!='1'||omap[x2][y1]!='1'||omap[x2][y2]!='1')return 0;
    for(i=x1+1;i<x2;i++)if(omap[i][y1]!='2'||omap[i][y2]!='2')return 0;
    for(i=y1+1;i<y2;i++)if(omap[x1][i]!='2'||omap[x2][i]!='2')return 0;
    for(i=x1+1;i<x2;i++)
    for(j=y1+1;j<y2;j++){
        if(omap[i][j]!='4')return 0;
    }
    return 1;
}
int main()
{
    while(cin>>n){
        x1=y1=MAX;
        x2=y2=-1;
        for(int i=0;i<n;i++)scanf("%s", omap[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
            if(omap[i][j]!='0'){
                x1=min(x1, i);
                y1=min(y1, j);
                x2=max(x2,i);
                y2=max(y2, j);
            }
        }
       if(check())cout<<"Yes"<<endl;
       else cout<<"No"<<endl;
    }
    return 0;
}
