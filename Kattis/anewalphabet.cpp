#include <bits/stdc++.h>

using namespace std;

string newAlph[] {
	"@",
	"8",
	"(",
	"|)",
	"3",
	"#",
	"6",
	"[-]",
	"|",
	"_|",
	"|<",
	"1",
	"[]\\/[]",
	"[]\\[]",
	"0",
	"|D",
	"(,)",
	"|Z",
	"$",
	"']['",
	"|_|",
	"\\/",
	"\\/\\/",
	"}{",
	"`/",
	"2"
};

inline int val(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A';
    }
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (val(s[i]) != -1) {
			cout << newAlph[val(s[i])];
		} else {
            cout << s[i];
		}
	}
	cout << "\n";
}
