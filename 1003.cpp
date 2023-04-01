#include<iostream>
#incude<string>
#include<cmath>
using namespace std;
int a[100001];
int ans[10001];
int mcha(int);
int main(void){
	int n;
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
		ans[i]= mcha
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
		else (minid>i) break;
	}
	return ret;
}

