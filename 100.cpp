#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
int ans[10001];
int n;
int mcha(int);
int main(void){
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int m;
	cin>>m;
	for(int i = 0;i<m;i++){
		int x;
		cin>>x;
		ans[i]= mcha(x);
	}
	for(int i =0;i<m;i++){
		cout<<ans[i]<<endl;
	}
}
int mcha(int b){
	int ret = a[n-1];
	int minid = 0;
	for(int i = n-1;i>=0;i--){
		int mc = abs(a[i]-b);
		if(mc<=ret) {
			ret = mc;
			minid = i;
		}
		else if(minid>i) break;
	}
	return a[minid];
}

