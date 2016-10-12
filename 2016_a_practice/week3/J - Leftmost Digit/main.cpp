#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int ans, n, i;
	double y, x;
	cin>>i;
	while(i--){
		cin>>n;
		x=floor(n*log10(n));
		y=n*log10(n)-x;
		ans=pow(10.0, y);
		cout<<ans<<endl;
	}
}
