#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void mysortprint(int*m) {
	sort(m, m + 3);
	for (int i = 0; i < 3; i++){
		cout << m[i]<<' ';
	}
}
int main(void) {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	mysortprint(a);
}