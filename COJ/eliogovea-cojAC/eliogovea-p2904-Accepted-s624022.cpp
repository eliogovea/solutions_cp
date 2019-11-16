#include <bits/stdc++.h>
using namespace std;

const int MaxLen = 100005;

struct big_int {
	int len, dig[MaxLen];
	big_int() {
		len = 1;
		for (int i = 0; i < MaxLen; i++) dig[i] = 0;
	}
	big_int(string &s) {
		len = s.size();
		for (int i = 0; i < len; i++) dig[i] = s[len - 1 - i] - '0';
	}
	void print() {
		for (int i = len - 1; i >= 0; i--)
			printf("%d", dig[i]);
		printf("\n");
	}

} a, b;
void sum() {
    if (a.len < b.len) for (int i = a.len; i < b.len; i++) a.dig[i] = 0;
    if (a.len > b.len) for (int i = b.len; i < a.len; i++) b.dig[i] = 0;
    a.len = max(a.len, b.len);
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        carry += a.dig[i] + b.dig[i];
        a.dig[i] = carry % 10;
        carry /= 10;
    }
    if (carry) a.dig[a.len++] = carry;
}
int n;
string str;

int main() {
	cin >> n;
	while (n--) {
        cin >> str;
		b = big_int(str);
		sum();
	}
    a.print();
}
