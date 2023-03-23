#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int a[12];
int main(void) {
	for (int i = 0; i < 12; i++) {
		cin >> a[i];
	}
	int rest = 0;
	int bank = 0;
	for (int i = 0; i < 12; i++) {
		if (a[i] <= rest + 300) {
			if (rest + 300 - a[i] >= 100) {
				bank += (rest + 300 - a[i]) / 100 * 100;
				rest = (rest + 300 - a[i]) % 100;
			}
			else {
				rest = rest + 300 - a[i];
			}
		}
		else {
			cout << -(i + 1);
			goto end;
		}
	}
	cout << bank * (1.2) + rest;
end:
	return 0;
}
