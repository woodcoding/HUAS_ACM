#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>
#include <map>
using namespace std;

#define MAX 1005
map<string, int> imap;

int maxv[MAX][2];
int t, n, v, ans, cnt;
string s;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        imap.clear();
        memset(maxv, 0, sizeof(maxv));
        ans = 0;
        cnt = 0;
        for(int i=0;i<n;i++){
            cin>>s>>v;
            if(!imap[s]){
                imap[s]=++cnt;
                maxv[cnt][0] = v;
            }
            else{
                int pos = imap[s];
                if(v>maxv[pos][0]){
                    maxv[pos][1] = maxv[pos][0];
                    maxv[pos][0] = v;
                }
                else if(v>maxv[pos][1])maxv[pos][1] = v;
            }
        }
        for(int i=1;i<=cnt;i++){
            ans += maxv[i][0];
            ans += maxv[i][1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
