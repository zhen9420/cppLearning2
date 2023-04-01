#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned long long d(int l);
int main(void){
	int a,b;
	cin>>a>>b;
	cout<<d(a)+d(b);
}
unsigned long long d(int l){
	ll m =l;
	unsigned long long ans = 0;
	int a[100000]={0};
	ll i = 0;
	for(;;i++){
		if(m==0) break;
		else{
			a[i]=m%2;
			m/=2;
		}
	}
	ll x = 1;
	for(ll j=0;j<=i;j++){
		ans += a[j]*x;
		x *=10;
	}
	return ans;
}

