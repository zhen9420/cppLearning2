#define _CRT_NO_WARNINGS
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int bisect1(int x,int l, int r);
int bisect2(int x, int l, int r);
int main(void) {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		
	}
}
int bisect1(int x, int l, int r) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (x < mid) r = mid;
		else l = mid + 1;
	}
	
}