#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll inf = 1e18;

bool criba[105];
vector<int> pr;
void Criba() {
	for (int i = 2; i * i <= 100; i++)
		if (!criba[i])
			for (int j = i * i; j <= 100; j += i)
				criba[j] = 1;
	for (int i = 2; i <= 100; i++)
		if (!criba[i]) pr.push_back(i);
}

vector<pair<ll, int> > v;

ll pw(ll a, int b) {
  ll r = 1ll;
  while (b--) r *= a;
  return r;
}

void form(ll r, int cd, int ind, int last) {
  v.push_back(make_pair(r, cd));
  for (int i = 1; i <= last; i++) {
    ll pp = pw(pr[ind], i);
    if (inf / pp > r) form(r * pp, cd * (i + 1), ind + 1, i);
  }
}

int tc;
ll n;

int main() {
  ios::sync_with_stdio(false);
  Criba();
  form(1, 1, 0, 63);
  sort(v.begin(), v.end());
  int s = v.size();

  pair<ll, int> pi = v[0];
  for (int i = 0; i < s; i++)
    if (v[i].second <= pi.second)
      v[i] = pi;
    else pi = v[i];

  cin >> tc;
  while (tc--) {
    cin >> n;
    pi = make_pair(n, 1000);
    cout << (--upper_bound(v.begin(), v.end(), pi))->first << '\n';
  }
}
