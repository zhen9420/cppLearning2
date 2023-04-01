#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000]
int main(void) {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>b[10000];
	}
	for(int i = 0;i<n;i++){
		if(a[i]<=b[i]) cout<<1<<endl;
		else cout<<a[i]*a[i]<<endl;
	}
	
}
