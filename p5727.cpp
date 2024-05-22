#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[10000];
int main(void){
	int n;
	cin>>n;
	int i = 0;
	a[i++] = n;
	while(n!=1){
		if(n%2!=0) {
			n = n*3 +1;
			a[i++] = n;
		}else {
			n /= 2;
			a[i++] = n;
		}
	}
	while(i--){
		cout<<a[i]<<' ';
	}
}
