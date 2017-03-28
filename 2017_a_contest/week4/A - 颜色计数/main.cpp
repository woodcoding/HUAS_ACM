#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[110][310][310];
int color[310][310];
int n, m, c, q, cmd, ans;

int lowbit(int k){return k&-k;}

void update(int clr, int x, int y, int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            cnt[clr][i][j]+=v;
        }
    }
}

int sum(int clr, int x, int y){
    int all=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            all+=cnt[clr][i][j];
        }
    }
    return all;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &color[i][j]);
            update(color[i][j], i, j, 1);
        }
    }
    scanf("%d", &q);
    int flag=0;
    while(q--){
        scanf("%d", &cmd);
        if(cmd==1){
            int x, y;
            scanf("%d%d%d", &x, &y, &c);
            update(color[x][y], x, y, -1);  //原来的颜色减一
            color[x][y]=c;
            update(color[x][y], x, y, 1);  //新增颜色加一
        }
        else if(cmd==2){
            int x1, x2, y1, y2;
            scanf("%d%d%d%d%d", &x1, &x2, &y1, &y2, &c);
            ans=sum(c, x2, y2)+sum(c, x1-1, y1-1)-sum(c, x2, y1-1)-sum(c, x1-1, y2);
            printf("%d\n", ans);
        }
    }
    return 0;
}
