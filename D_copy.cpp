#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define int __int128
string s;
int wei(string t){
    int an = 0;
    for(int i = 0;i<t.length();i++){
        an*=10;
        an += (t[i] - '0');
    }
    return an;
}
string l,r;
void solve(){
    int ans = 0,sd = 0;
    cin>>l>>r;
    int fl = wei(l);
    int fr = wei(r);
    cin>>s;
    int len = s.length(); 
    for(int i = 0;i<len;i++){
        int t = 0;
        if(s[i] == '0'){
            sd+=1;
            continue;
        }
        if(s[i] != '0'){
            for(int j = 0;j<30&&j+i<len;j++){
            t*=10;
            t += (s[i+j] - '0');
            if(t>fr)
            break;
            if(t>=fl)
            ans += sd + 1;
            }
        }
        sd = 0;
    }
    cout<<(long long)ans;
}
signed main(){
    solve();
    return 0;
}
