#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
#define LL long long
const int maxn=1e7;
int n, j, len;
char op[2], s[maxn];
LL v;
stack<LL> num;
stack<char> c;

int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        v=0,len=strlen(s);
        for(j=0;j<strlen(s);j++){
            if(s[j]<'0'||s[j]>'9')break;
            v=v*10+s[j]-'0';
        }
        num.push(v);
        while(j<len){
            op[0]=s[j], j++, v=0;
            while(s[j]>='0'&&s[j]<='9')v=v*10+s[j++]-'0';
            if(op[0]=='*'){
                v=num.top()*v;
                num.pop();
                num.push(v);
            }
            else if(op[0]=='/'){
                v=num.top()/v;
                num.pop();
                num.push(v);
            }
            else{
                num.push(v);
                c.push(op[0]);
            }
        }
        v=0;
        while(!c.empty()){
            if(c.top()=='+')v+=num.top();
            else v-=num.top();
            num.pop();c.pop();
        }
        v+=num.top();
        num.pop();
        printf("%lld\n", v);
    }
    return 0;
}
