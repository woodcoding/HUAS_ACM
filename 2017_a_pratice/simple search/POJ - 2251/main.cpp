#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;

const int maxn=35;
struct P{
    int z, x, y;
}st, ed;
queue <P> Q;
char mat[maxn][maxn][maxn];
int step[maxn][maxn][maxn];
int to[6][3]={
    0, 0, 1,
    0, 0, -1,
    0, 1, 0,
    0, -1, 0,
    1, 0, 0,
    -1, 0, 0
    };
int l, r, c, ex, ey, ez, ans;

bool check(int z, int x, int y){
    if(mat[z][x][y]=='E')return 1;
    if(z<1||z>l||x<1||x>r||y<0||y>c||step[z][x][y]||mat[z][x][y]!='.'||mat[z][x][y]=='S')return 0;
    return 1;
}

int bfs(){
    while(!Q.empty()){
        P now=Q.front(), go;Q.pop();
        int num=step[now.z][now.x][now.y];
        for(int i=0;i<6;i++){
            go.z=now.z+to[i][0];
            go.x=now.x+to[i][1];
            go.y=now.y+to[i][2];
            if(check(go.z, go.x, go.y)){
                if(go.z==ez&&go.x==ex&&go.y==ey)return num+1;
                step[go.z][go.x][go.y]=num+1;
                Q.push(go);
            }
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d%d", &l, &r, &c)&&l+r+c){
        ans=0;
        memset(step, 0, sizeof(step));
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                scanf("%s", &mat[i][j][1]);
                for(int k=1;k<=c;k++){
                    if(mat[i][j][k]=='S'){st.z=i;st.x=j;st.y=k;}
                    else if(mat[i][j][k]=='E'){ez=i;ex=j;ey=k;}
                }
            }
        }
        while(!Q.empty())Q.pop();
        Q.push(st);
        ans=bfs();
        if(ans)printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }
    return 0;
}
