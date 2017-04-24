#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

#define BMAX 34
int t, n, m, x;
char cmd[10];
int pos, bin[BMAX], xx, ans;

struct Node{
    int pos;
    Node *next[2];
    Node(){pos=0;next[0]=NULL;next[1]=NULL;}
};

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void Insert_num(Node *p, int b[], int pos){
    Node *now=p;
    for(int i=0;i<32;i++){
        if(now->next[b[i]]==NULL){
            now->next[b[i]]=new Node;
        }
        now=now->next[b[i]];
    }
    now->pos=pos;
}

int Search_num(Node *p, int b[]){
    Node *now=p;
    for(int i=0;i<32;i++){
        int pos=b[i];
        if(now->next[!pos]!=NULL)pos=!pos;
        now=now->next[pos];
    }
    return now->pos;
}

void Del(Node *p){
    if(p->next[0]!=NULL)Del(p->next[0]);
    if(p->next[1]!=NULL)Del(p->next[1]);
    delete p;
}

void Bin(int a, int b){
    xx=x=read();
    pos=32;
    for(int i=0;i<BMAX;i++)bin[i]=a;
    while(x){
        bin[--pos]=x&1?b:a;
        x>>=1;
    }
}

int main()
{
    t=read();
    while(t--){
        int k;
        k=read();
        Node *node=new Node;
        while(k--){
            scanf("%s", cmd);
            if(cmd[0]=='i'){
                Bin(0, 1);
                Insert_num(node, bin, xx);
            }
            else if(cmd[2]=='i'){
                Bin(1, 0);
                ans=Search_num(node, bin);
                printf("%d\n", ans^xx);
            }
            else{
                Bin(0, 1);
                ans=Search_num(node, bin);
                printf("%d\n", ans^xx);
            }
        }
        Del(node);
    }
    return 0;
}
