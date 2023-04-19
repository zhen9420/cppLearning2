#include<iostream>
#include<vector>
using namespace std;
void show(vector<int>, int len);
void show2(vector<int>);
int main(void) {
	int a[] = { 0,1,2,3,4 };
	vector<int> A, B, C, D;
	A.assign(a, a + 5);//左闭右开；
	B.assign(5, 4);//5个4;
	//C = B;//vector_copy重载
	A.swap(B);//交换A,B;
	/*B.push_back(5);
	B.pop_back();
	B.pop_back();*/
	show(B, B.size());
	B.insert(B.end(),a,a+5);
	show2(B);
}
void show(vector<int> v, int l) {
	for (int i = 0; i < l; i++) {
		cout << v.at(i)<<' ';
	}
}
void show2(vector<int> v) {
	vector<int>::iterator it = v.begin();
	for (; it < v.end(); it++) {
		cout << *it << ' ';
	}

}
