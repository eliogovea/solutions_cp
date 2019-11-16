#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;

string str;
int digits[MAXN], top = 0, x;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> str;
	while (true) {
		int s = str.size();
		for (int i = s - 2; i >= 0; i--)
			digits[top++] = str[i] - '0';
		x = (str[s - 1] - '0'  + 1) / 2;

		int carry = 0;
		for (int i = 0; i < top; i++) {
			carry += digits[i] * 5;
			digits[i] = carry % 10;
			carry /= 10;
		}
		while (carry) {
			digits[top++] = carry % 10;
			carry /= 10;
		}

		carry = x;
		for (int i = 0; carry; i++) {
			carry += digits[i];
			digits[i] = carry % 10;
			carry /= 10;
			top = max(top, i + 1);
		}
        cout << "f(" << str << ") = ";
		for (int i = top - 1; i >= 0; i--) {
			cout << digits[i];
			digits[i] = 0;
		}
		cout << '\n';
		top = 0;

		cin >> str;
		if (str[0] == '-') break;
		else cout << '\n';
	}
}
