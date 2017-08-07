#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c[10][30];
int n, h, m;

bool col(int x, int y){    //ÁÐ
    return c[x][y]=='X'&&c[x+1][y]=='X'?1:0;
}
bool row(int x, int y){    //ÐÐ
    return c[x][y]=='X'&&c[x][y+1]=='X'?1:0;
}

int getNum(int y){
    int val=-1;
    if(col(2, y)&&col(5, y)){     //068
        if(!col(2, y+3))val=6;
        else if(row(4, y+1))val=8;
        else val=0;
    }
    else if(col(2, y)&&!col(5, y)){    //459
        if(!row(1, y+1))val=4;
        else if(!col(2, y+3))val=5;
        else val=9;
    }
    else if(!col(2, y)&&col(5, y))val=2;       //2
    else {    //137
        if(row(4, y+1))val=3;
        else if(row(1, y+1))val=7;
        else val=1;
    }
    return val;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    while(n--){
        for(int i=1;i<=7;i++)scanf("%s", &c[i][1]);
        h=getNum(1);
        h=h*10+getNum(6);
        m=getNum(13);
        m=m*10+getNum(18);
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}
