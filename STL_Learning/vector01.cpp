#include<iostream>
#include <vector>
using namespace std;
int main(void) {
	int arr[] = { 1,2,3,4,5 };
	vector<int> v1(arr, arr + 3);
	vector<int >v2(3, 10);
	//for (int i = 0; i < 3; i++){
	//	cout << v1[i] << ' ';
	//}
	vector<int > v3(v1);
	for (int i = 0; i < 3; i++) {
		cout << v3[i] << ' ';
	}
}