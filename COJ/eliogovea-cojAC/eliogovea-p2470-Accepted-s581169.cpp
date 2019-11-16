#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, k;
char str[25];
vector<int> v[25];
ll sol;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int s = strlen(str);
		int p = v[s].end() - lower_bound(v[s].begin(), v[s].end(), i - k);
		sol += (ll)p;
		v[s].push_back(i);
	}

	printf("%lld\n", sol);
}
