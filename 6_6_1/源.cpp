#include<iostream>
#include<string>
using namespace std;
struct student {
	string number;
	string name;
	int grade;
};
int main(void) {
	student class1[10];
	for (int i = 0; i < 10; i++) {
		cin >> class1[i].number >>class1[i]. name >> class1[i].grade;
	}
	for (int i = 0; i < 10; i++) {
		cout<<class1[i].number<<  class1[i].name << class1[i].grade<<endl;
	}
}