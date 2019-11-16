#include <bits/stdc++.h>
using namespace std;

const int MaxLen = 1010;

struct BigInt {
	int len, dig[MaxLen];
	BigInt() {
		len = 1;
		for (int i = 0; i < MaxLen; i++)
			dig[i] = 0;
	}
	BigInt(string &s) {
	    len = 1;
	    for (int i = 0; i < MaxLen; i++) dig[i] = 0;
		len = s.size();
		for (int i = 0; i < len; i++)
			dig[i] = s[len - 1 - i] - '0';
	}
	void sum(BigInt &b) {
		len = max(len, b.len);
		int carry = 0;
		for (int i = 0; i < len; i++) {
			carry += dig[i] + b.dig[i];
			dig[i] = carry % 10;
			carry /= 10;
		}
		if (carry) dig[len++] = carry;
	}
	void print() {
		for (int i = len - 1; i >= 0; i--)
			printf("%d", dig[i]);
		printf("\n");
	}
} a, b;

int n;
string str;

int main() {
	scanf("%d", &n);
	while (n--) {
		cin >> str;
		b = BigInt(str);
		//b.print();
		//a.print();
		a.sum(b);
	}
	a.print();
}
