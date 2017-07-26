#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000005;
const int maxm=105;
long long data[maxn],ans[maxm];
int q[maxm], pos[maxm];
unsigned n, m, a, b, c, x, y, z, cas=0;

unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

bool cmp(int ca, int cb){return q[ca]<q[cb];}

int main()
{
    while(~scanf("%u%u%u%u%u", &n, &m, &a, &b, &c)){
        for(int i=0;i<m;i++){
            scanf("%u", &q[i]);
            pos[i]=i;
        }
        x=a;y=b;z=c;
        for(int i=0;i<n;i++){
            data[i]=rng61();
        }
        sort(pos, pos+m, cmp);
        pos[m]=m;
        q[m]=n;
        for(int i=m-1;i>=0;i--){
            if(q[pos[i]]==q[pos[i+1]]){
                ans[i]=ans[i+1];
            }
            else{
                nth_element(data, data+q[pos[i]], data+q[pos[i+1]]);
                ans[i]=data[q[pos[i]]];
            }
        }
        printf("Case #%u:", ++cas);
        for(int i=0;i<m;i++){
            printf(" %lld", data[q[i]]);
        }
        printf("\n");
    }
    return 0;
}
