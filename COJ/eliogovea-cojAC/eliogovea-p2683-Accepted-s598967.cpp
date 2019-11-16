#include <iostream>
#include <algorithm>
using namespace std;

const char c[] = {'0', '1', '2', '3', '4',
					'5', '6', '7', '8', '9',
					'A', 'B', 'C', 'D', 'E', 'F'};
int tc, n, b;
string s;

int main() {
	for (cin >> tc; tc--;) {
		cin >> n >> b;
		s = "";
		while (n) {
			s += c[n % b];
			n /= b;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}
