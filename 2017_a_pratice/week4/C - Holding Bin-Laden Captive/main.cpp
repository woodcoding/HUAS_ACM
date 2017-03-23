#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x, y, z, ans, j;
    while(~scanf("%d%d%d",&x,&y,&z)&&x+y+z){
        ans=0;
        int up=x+y*2+z*5+1;
        for(j=1;j<=up;j++){
            int i=j;
            int zz=i/5;
            if(zz<=z)i-=zz*5;
            else i-=z*5;
            int yy=i/2;
            if(yy<=y)i-=yy*2;
            else i-=y*2;
            if(i>x){ans=1;break;}
        }
        printf("%d\n", j);
    }
    return 0;
}
