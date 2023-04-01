#include<iostream>
#include<string>
using namespace std;
int main(void) {
	string s;
	char opreated[100000] ={'0'};
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
				opreated[last]=s[i];
				last++;
			}
			else if (s[i] == 'D') {
				x++;
				opreated[last]=s[i];
				last++;
			}
			else if (s[i] == 'S') {
				y--;
				last = i;
			}
			else if (s[i] == 'W') {
				y++;
				opreated[last]=s[i];
				last++;
			}
			else {
				if (i == 0||last==0) continue;
				if (opreated[last-1] == 'A') {
						x++;
						last--;
				}
				else if (opreated[last-1] == 'D') {
					x--;
					last--;
				}
				else if (opreated[last-1] == 'S') {
					y++;
					last--;
				}
				else if (opreated[last-1] == 'W') {
					y--;
					last--;
				}
			}

		}
		cout << x << ' ' << y;
	}
	
}
