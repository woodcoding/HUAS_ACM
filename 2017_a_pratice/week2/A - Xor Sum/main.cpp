#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

#define MAX 100005
#define BMAX 34
int t, n, m, x;
int res[MAX], ans;

struct Node{
    int pos;
    Node *next[2];
    Node(){
        pos=0;
        next[0]=NULL;
        next[1]=NULL;
    }
};

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
        //cout<<"--pos:"<<pos<<endl;
    }
    return now->pos;
}

int main()
{
    scanf("%d", &t);
    for(int k=0;k<t;k++){
        scanf("%d%d", &n, &m);
        Node *node=new Node;
        for(int i=0;i<n;i++){
            scanf("%d", &res[i]);
            x = res[i];
            int pos=32, bin[BMAX];
            memset(bin, 0, sizeof(bin));
            while(x){
                if(x&1)bin[--pos]=1;
                else bin[--pos]=0;
                x>>=1;
            }
            Insert_num(node, bin, i);
        }
        printf("Case #%d:\n", k+1);
        for(int i=1;i<=m;i++){
            scanf("%d", &x);
            int pos=32, bin[BMAX];
            memset(bin, 0, sizeof(bin));
            while(x){
                if(x&1)bin[--pos]=1;
                else bin[--pos]=0;
                x>>=1;
            }
            ans=Search_num(node, bin);
            printf("%d\n", res[ans]);
        }
    }
    return 0;
}
