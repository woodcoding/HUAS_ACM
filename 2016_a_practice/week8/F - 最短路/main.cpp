#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

#define MAX 10010
#define MAXV 1000000000
struct Word{
    char s[5];
    char e[5];
    int v;
}word[MAX];

int dis[MAX], flag[MAX], go[MAX], n, v;
char str[18];

void Dij(){
    dis[1] = 0;
    go[1] = 1;
    for(int i=1;i<=n;i++){
        int cur = 1;
        int nowv = MAXV;
        for(int j=1;j<=n;j++){
            if(!go[j]&&dis[j]<nowv){
                cur=j;
                nowv=dis[cur];
            }
        }
        go[cur] = 1;
        //cout<<"go from:"<<cur<<endl;
        for(int j=1;j<=n;j++){
            if(cur==j)continue;
            if(!strcmp(word[cur].e, word[j].s) && !go[j]){
                //cout<<"###:"<<dis[cur]+word[cur].v<<endl;
                if(dis[cur]+word[cur].v<dis[j]){
                        dis[j]=dis[cur]+word[cur].v;
                        //cout<<dis[j]<<endl;
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d", &n) && n){
        memset(go, 0, sizeof(go));
        for(int i=1;i<=n;i++)dis[i]=MAXV;
        for(int i=1;i<=n;i++){
            scanf("%d %s", &v, &str);
            word[i].v = v;
            for(int j=0;j<4;j++)word[i].s[j]=str[j];
            int tpos = 0;
            int pos = strlen(str)-4;
            for(int k=pos;k<pos+4;k++)word[i].e[tpos++]=str[k];
            dis[i] = 10e9;
            word[i].s[4]=word[i].e[4]='\0';
            //cout<<"--f:"<<word[i].s<<"  "<<word[i].e<<endl;
        }
        Dij();
        if(!go[n])printf("-1\n");
        else printf("%d\n", dis[n]);
    }
    return 0;
}
