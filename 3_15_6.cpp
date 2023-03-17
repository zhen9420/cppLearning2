#include<bits/stdc++.h>
using namespace std;
int main(void){
	
	double n;
	cin>>n;
	double g5 = pow(5.0,1.0/2);
	double c1=pow((1+g5)/2,n);
	double c2 = pow((1-g5)/2,n);
	double ans = (c1-c2)/g5;
	cout<<fixed<<setprecision(2)<<ans;

}
