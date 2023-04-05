#include<iostream>
#include<cmath>
#include<string>
using namespace std;
typedef __int128 lll; 
typedef long long ll;
lll nl,nr;
string l,r,s;
lll count(string,ll);
int main(void){
	 cin>>l>>r>>s;
	 nl = count(l,l.length());
	 nr = count(r,r.length());
	 ll n0 =0;
	 ll ans = 0;
	 for(ll i =0;i<s.length();i++){
	 	lll num = 0;
	 	if(s[i]=='0'){
	 		n0++;
	 		continue;
		}
		else{
			for(int j =0;j+i<s.length();j++){
				num *= 10;
				num += s[i+j]-'0';
				if(num>nr) break;
				else if(num>=nl) ans += n0+1;
			}
			n0 = 0;
		}
	 }
	 cout<<ans;
}
lll count(string x,ll l){
	lll ret = 0;
	lll t = pow(10,l-1);
	for(lll i = 0;i<l;i++){
		ret += (x[i]-'0') *t;
		t/=10;	
	}
	return ret;
	
}
