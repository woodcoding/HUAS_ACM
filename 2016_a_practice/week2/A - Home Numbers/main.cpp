#include<iostream>
using namespace std;
int main()
{
	int n,a,ans;
	while(cin>>n>>a){
		if(a&1)ans=(a+1)>>1;
		else ans=n/2+1-a/2;
		cout<<ans<<endl;
	}
	return 0;
}
