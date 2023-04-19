#include<iostream>
using namespace std;
const int n = 10;
int main(void) {
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0;j< 9 - i; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j+1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}