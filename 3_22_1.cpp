#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x;
	if(x<1) y=x;
	if(x>=1&&x<10) y=2*x-1;
	if(x>=10) y=3*x-11;
	cout<<y;
}
