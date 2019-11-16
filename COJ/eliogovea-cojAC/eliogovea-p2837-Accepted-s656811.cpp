#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 100000000;

int tc, id, f, c;
vector<int> v;
vector<int>::iterator it;

int main() {
  for (int a = 0, b = 0; ; a++, b += a) {
    v.push_back(b);
    if (b > inf) break;
  }

  cin >> tc;
  while (tc--) {
    cin >> id;
    it = lower_bound(v.begin(), v.end(), id);
    f = it - v.begin(); c = 1;
    int x = *it, diff = x - id;
    f -= diff;
    c += diff;
    //cout << f << " " << c << "\n";
    if (f == 1 && c == 1) cout << "0\n";
    else if (f == 1) {
      if (c & 1) cout << "-";
      cout << c / 2 << "\n";
    }
    else {
      if (!(c & 1)) cout << "-";
      int x, cont = 0;
      for (x = 1; ; x++) {
        if (__gcd(f, x) == 1) cont += 2;
        if (cont >= c) break;
      }
      cout << x << "/" << f << "\n";
    }
  }
}
