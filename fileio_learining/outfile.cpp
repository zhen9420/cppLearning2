#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
int main(void) {
	using namespace std;
	string automobile;
	int year;
	double a_price, d_price;
	ofstream outfile;
	outfile.open("carinfo.text");
	cout << "Enter the make and the model of automobile:";
	getline(cin, automobile);
	cout << "Enter the model year:";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >>  a_price;
	d_price = 0.913 * a_price;
//display information on screen with cout
	cout << "Make and model: " << automobile << endl;
	cout << "Year£º" << year << endl;
	cout << fixed << setprecision(2) << "Was asking $" << a_price << endl;
	cout <<"Now asking $"<< d_price<<endl;
//now do exact same things using outfile instead of endl;
	outfile << "Make and model: " << automobile << endl;
	outfile << "Year£º" << year << endl;
	outfile << fixed << setprecision(2) << "Was asking $" << a_price << endl;
	outfile << "Now asking $" << d_price << endl;
	outfile.close();

}