#include<iostream>
#include<cmath>
#include<string>
using namespace std;
typedef __int128 lll; 
typedef long long ll;
lll nl,nr;
string l,r,s;
__int128 read() {
    __int128 x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
int main(void){
	 nl=read();
	 nr= read();
	 cin>>s; 
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

