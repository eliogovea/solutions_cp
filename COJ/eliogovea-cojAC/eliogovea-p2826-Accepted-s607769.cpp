#include <cstdio>

const int MAXN = 100010, mod = 1000000007;

int n, dp[MAXN];
char str[25], text[MAXN];

struct node {
	node *next[26];
	bool fin;
} root;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		node *ptr = &root;
		for (char *p = str; *p; p++) {
			if (ptr->next[*p - 'a'] == NULL)
				ptr->next[*p - 'a'] = new node();
			ptr = ptr->next[*p - 'a'];
		}
		ptr->fin = 1;
	}
	scanf("%s", text);
	dp[0] = 1;
	int len;
	for (len = 0; text[len]; len++)
		if (dp[len]) {
			node *ptr = &root;
			for (int j = len; text[j]; j++) {
				if (ptr->next[text[j] - 'a'] == NULL) break;
				ptr = ptr->next[text[j] - 'a'];
				if (ptr->fin) dp[j + 1] = (dp[j + 1] + dp[len]) % mod;
			}
		}
	printf("%d\n", dp[len]);
}
