#include <iostream>
using namespace std;

const int MAX1 = 1010, MAX2 = 3010;

int a1[MAX1], ///a1[i] contiene la cantidad de digitos de la cadena que llega hasta i
    a2[MAX2]; ///a2[i] contiene el ultimo numero en la cadena de largo i

string in;

inline int dig(int n) {
	if (n < 10) return 1;
	if (n < 100) return 2;
	if (n < 1000) return 3;
}

void solve(string &str) {
    int s = (int)str.size();
	if (s <= 10) {
		for (int i = 0; i < s; i++)
			if (str[i] == '0') {
                cout << a2[s] - a2[s - i] << endl;
                return;
			}
	}

	for (int i = 0; i < s; i++)
		if (str[i] == '0') {
			bool b = (str[(i + 1) % s] == '1' && str[(i + 2) % s]  == '2' && str[(i + 3) % s] == '3');
			if (b) {
                cout << a2[s] - a2[s - i] << endl;
                return;
			}
		}
}

int main() {
	a1[0] = 1;
	a2[1] = 0;
	for (int i = 1; i < 1000; i++) a2[a1[i] = a1[i - 1] + dig(i)] = i;
	while (cin >> in) solve(in);
}
