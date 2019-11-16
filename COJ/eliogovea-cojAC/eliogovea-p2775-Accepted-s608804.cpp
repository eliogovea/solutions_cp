#include <iostream>
using namespace std;

int n;
string word;

int main() {
	cin >> n;
	while (n--) {
		cin >> word;
		char ch = word[0];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			cout << word << "cow" << endl;
		}
		else {
			for (int i = 1; i < word.size(); i++) cout << word[i];
			cout << word[0] << "ow" << endl;
		}
	}
}
