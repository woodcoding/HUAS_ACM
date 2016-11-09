#include<iostream>
using namespace std;

long long ans;
int n, now;
int prime[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void dfs(int dep, long long tmp, int cnt){
	if(dep>=16)return;
	if(cnt>now){
		ans=tmp;
		now=cnt;
	}
	if(cnt==now && tmp<ans)ans=tmp;
	for(int i=1;i<=63;i++){
		if(tmp*prime[dep]>n)break;
		dfs(dep+1, tmp*=prime[dep], cnt*(i+1));
	}
}

int main()
{
	while(cin>>n){
		now=0;
		ans=2000000000;
		dfs(0, 1, 1);
		cout<<ans<<endl;
	}
	return 0;
}
