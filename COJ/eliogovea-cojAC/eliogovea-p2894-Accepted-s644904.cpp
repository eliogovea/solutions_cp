#include <cstdio>

const int MAXN = 1005, MAXK = 205;

int n, k, a[MAXN][MAXN], dp[MAXK][MAXN], sol;

const int BUFFSIZE = 10240;
char BUFF[BUFFSIZE + 1], *ppp = BUFF;
int RR, CHAR, SIGN, BYTES = 0;
#define GETCHAR(c) { \
        if(ppp-BUFF==BYTES && (BYTES==0 || BYTES==BUFFSIZE)) { BYTES = fread(BUFF,1,BUFFSIZE,stdin); ppp=BUFF; } \
        if(ppp-BUFF==BYTES && (BYTES>0 && BYTES<BUFFSIZE)) { BUFF[0] = 0; ppp=BUFF; } \
        c = *ppp++; \
}

#define DIGIT(c) (((c) >= '0') && ((c) <= '9'))
#define MINUS(c) ((c)== '-')
#define GETNUMBER(n) { \
        n = 0; SIGN = 1; do { GETCHAR(CHAR); } while(!(DIGIT(CHAR) || MINUS(CHAR))); \
        if(MINUS(CHAR)) { SIGN = -1; GETCHAR(CHAR); } \
        while(DIGIT(CHAR)) { n = 10*n + CHAR-'0'; GETCHAR(CHAR); } if(SIGN == -1) { n = -n; } \
}

int main() {
	GETNUMBER(n);
	GETNUMBER(k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			GETNUMBER(a[i][j]);
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}

	for (int i = 1; i <= n; i++)
		dp[1][i] = a[i][i];
	sol = dp[1][n];
	for (int i = 2, x, y; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			x = 1 << 29;
			for (int k = i; k <= j; k++) {
				y = dp[i - 1][k - 1] + a[j][j] - a[j][k - 1] - a[k - 1][j] + a[k - 1][k - 1];
				if (y < x) x = y;
			}
			dp[i][j] = x;
		}
		if (sol > dp[i][n]) sol = dp[i][n];
	}
	printf("%d\n", sol >> 1);
}
