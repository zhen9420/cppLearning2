#include<iostream>
#include<string>;
using namespace std;
string s;
int main(void) {
	int n;
	cin >> n;
	int x = 0, y = 0;
	int last = 0;
	if (n == 0) {
		cout << 0 << ' ' << 0;
	}
	else {
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') {
				x--;
				last = i;
			}
			else if (s[i] == 'D') {
				x++;
				last = i;
			}
			else if (s[i] == 'S') {
				y--;
				last = i;
			}
			else if (s[i] == 'W') {
				y++;
				last = i;
			}
			else {
				if (last == -1) continue;
				else {
					if (s[last] == 'A') {
						x++;
						last--;
					}
					else if (s[last] == 'D') {
						x--;
						last--;
					}
					else if (s[last] == 'S') {
						y++;
						last--;
					}
					else if (s[last] == 'W') {
						y--;
						last--;
					}

				}
			}

		}
		cout << x << ' ' << y;
	}
	
}
