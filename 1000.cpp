#include<bits/stdc++.h>
using namespace std;
string s;
int num (int begin ,int end);
int num0(int len);
int main(void){
	int l,r;
	cin>>l>>r;
	getchar();
	getline(cin,s);
	int n0=num0(s.length());
	long long ans =0;
	for(int i = 0;i<s.length();i++){
		for(int j = 0;j<s.length();j++){
			if(j+i<s.length()){
				int n = num(j,j+i);
				if(n>=l&&n<=r) ans++;
				else if(n>r&&n/r>pow(10,n0)
			}
			else break;
		}
	}

	cout<<ans;
	
}
int num0(int len){
	int ret = 0;
	
	for(int i =0;i<len;i++){
		int max = 0;
		if(s[i]=='0'){
			max++;
			for(int j = i+1;j<len;j++){
				if(s[j]!='0') break;
				else max++;
			}
		}
		if(max>ret) ret = max;
	}
	return ret;
}
int num(int b,int e){
	int ret  =0;
	int m = e-b;
	int b1 = b;
	for(int i =0;i<=m;i++){
		ret+= (s[b1]-'0')*pow(10,e-b-i);
		b1++;
	}
	return ret;
}
