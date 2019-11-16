#include <cstdio>
#include <algorithm>
using namespace std;

char str[1010];
int arr[1010], ind;
int main() {
	gets(str);
	int num = 0;
	for (char *p = str; *p; p++) {
		if (*p < '0' || *p >'9') {
			arr[ind++] = num;
			num = 0;
		}
		else num = 10 * num + *p - '0';
	}
	arr[ind++] = num;
	sort(arr, arr + ind);
	for (int i = 0; i < ind; i++) printf("%d%c", arr[i], (i == ind - 1) ? '\n' : '+');
}
