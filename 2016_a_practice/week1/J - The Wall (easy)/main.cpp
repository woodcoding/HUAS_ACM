#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MAX 100+10
char omap[MAX][MAX];
int flag[MAX][MAX];
int r, c, i, j, cnt;

int di[4][2] = {1,0,0,-1,-1,0,0,1}; // обвСиоср

void dfs(int x, int y, int dcnt){
    if(x<1||y<1||x>r||y>c)return;
    if(omap[x][y]=='.' || flag[x][y])return;
    flag[x][y]=dcnt;
    for(int m=0;m<4;m++){
        dfs(x+di[m][0], y+di[m][1], dcnt);
    }
}

int main(){
    while(cin>>r>>c){
        cnt = 0;
        memset(flag, 0, sizeof(flag));
        for(i=1;i<=r;i++)scanf("%s", &omap[i][1]);
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                if(omap[i][j]=='B' && flag[i][j]==0)
                {
                    dfs(i, j, ++cnt);
                }
            }
        }
        cout<<cnt<<endl;
        }
    return 0;
}
