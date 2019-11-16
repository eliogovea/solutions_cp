#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    n = (n * 13821) % 32768;
    cout << n << " : " << 1 + n % 7 << '\n';
  }
}
