#include<iostream>
using namespace std;
const int n = 5;
int main(void) {
	int x;
	int a[n] = { 1,2,3,4,5 };
	int b[n + 1] = { 0 };
	cout << "原数组:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << "输入：" << endl;
	cin >> x;
	if (x < a[0]) {
		b[0] = x;
		for (int i = 0; i < n; i++) {
			b[i + 1] = a[i];
		}
	}
	else if (x > a[n-1]) {
		b[n] = x;
		for (int i = 0; i < n; ++i) {
			b[i] = a[i];
		}
	}
	else {
		for (int i = 0; i < n-1; i++) {
			if (x >= a[i] && x <= a[i + 1]) {
				for (int j = 0; j <= i; j++) {
					b[j] = a[j];
				}
				b[i + 1] = x;
				for (int j = i + 2; j < n + 1; j++) {
					b[j] = a[j - 1];
				}
			}
		}
	}
	for (int i = 0; i < n+1; i++) {
		cout << b[i] << ' ';
	}
}