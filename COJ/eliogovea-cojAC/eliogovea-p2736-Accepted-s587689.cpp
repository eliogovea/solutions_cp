#include <cstdio>
#include <iostream>
using namespace std;

char str[1000010];

int main()
{
	scanf("%s", str);
	printf("%s\n", str);
	int n = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '1') n++;
	if (n > 1)
		while (true)
		{
			int bits = 0;
			int a[100], last = 0;
			for (int i = 0; (1 << i) <= n; i++)
				if (n & (1 << i)) {a[i] = 1; last = max(last, i); bits++;}
				else a[i] = 0;
			for (int i = last; i >= 0; i--) printf("%d", a[i]);
			printf("\n");
			if (bits == 1)break;
			n = bits;
		}
}