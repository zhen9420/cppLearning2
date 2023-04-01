#include<bits/stdc++.h>
using namespace std;
int main(void){
	string s[11];
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>s[i];
	}
	for(int i = 0;i<q;i++){
		int ans =0;
		for(int j = 0;j<s[i].length();j+=2){
			if(s[i][j]=='m'&&s[i][j+1]=='q') ;
			else{
				ans = 1;
				break;
			}
		}
		if(ans==1){
			cout<<"No"<<endl;
		}
		else cout<<"Yes" <<endl;
	}
} 
