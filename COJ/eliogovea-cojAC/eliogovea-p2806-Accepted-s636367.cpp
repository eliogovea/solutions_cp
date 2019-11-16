#include <iostream>
#include <stack>

using namespace std;

int n, k, p;
string str, sol;
stack<char> S;

int main() {
	cin >> n >> k >> str;
	for (int i = 0; i < n; i++) {
    if (p != k)
      while (!S.empty() && S.top() < str[i]) {
        S.pop();
        p++;
        if (p == k) break;
      }
    if (S.size() != n - k) S.push(str[i]);
	}
	while (!S.empty()) {
		sol += S.top();
		S.pop();
	}
	for (int i = sol.size() - 1; i >= 0; i--)
    cout << sol[i];
  cout << '\n';
}
