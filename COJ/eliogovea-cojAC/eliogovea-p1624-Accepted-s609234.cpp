#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

char str[MAXN];
bool pal[MAXN][MAXN];
int dp[MAXN], slen;

int main() {
	scanf("%s", str + 1);
	slen = strlen(str + 1);

	for (int i = 1; i <= slen; i++) pal[i][i] = 1;
	for (int i = 1; i < slen; i++) pal[i][i + 1] = (str[i] == str[i + 1]);
	for (int len = 3; len <= slen; len++)
		for (int beg = 1; beg + len - 1 <= slen; beg++)
			pal[beg][beg + len - 1] = ((str[beg] == str[beg + len - 1]) && pal[beg + 1][beg + len - 2]);

	for (int i = 1; i <= slen; i++) dp[i] = 1 << 29;
	for (int i = 1; i <= slen; i++)
		for (int j = i; j <= slen; j++)
			if (pal[i][j]) dp[j] = min(dp[j], dp[i - 1] + 1);
	printf("%d\n", dp[slen]);
}
