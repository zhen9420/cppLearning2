#include<iostream>
using namespace std;
const int n = 10;
int main(void) {
	int a[n][n] = { 1 };
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				cout << endl;
				break;
			}
			else {
				cout << a[i][j] << ' ';
			}
		}
	}
}