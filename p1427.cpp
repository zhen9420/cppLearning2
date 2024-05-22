#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	int x;
	cin>>x;
	int i = 0;
	while(x!=0){
		a[i] = x;
		i++;
		cin>>x;
	}
	i--;
	while(i>-1){
		cout<<a[i]<<' ';
		i--;
	}
}
