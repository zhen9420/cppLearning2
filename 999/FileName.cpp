#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int main(void) {
	string s1,s2 ;
	cin >> s1;
	s2 = s1+"b";
	unsigned long long ans1 = 0,ans2=0;
	unsigned long long numa = 1;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == 'a') numa++;
		else ans1 += (numa * (numa - 1)) / 2;
	}
	numa = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == 'a') numa++;
		else ans2 += (numa * (numa - 1)) / 2;
	}
	cout << max(ans1, ans2);
	
}