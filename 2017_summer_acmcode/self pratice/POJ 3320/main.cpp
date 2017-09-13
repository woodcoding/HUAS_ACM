#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
const int maxn=1000005;
int p, data[maxn];
set<int> book;
map<int, int> cnt;

int main()
{
    while(~scanf("%d", &p)){
        book.clear();
        cnt.clear();
        for(int i=0;i<p;i++){
            scanf("%d", &data[i]);
            book.insert(data[i]);
        }
        int all=book.size();
        int l=0, r=0, ans=p, num=0;
        for(;;){
            while(r<p && num<all){
                if(cnt[data[r]]==0){
                    num++;
                }
                cnt[data[r]]++;
                r++;
            }
            if(num<all)break;
            ans=min(ans, r-l);
            if(--cnt[data[l++]]==0)num--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
