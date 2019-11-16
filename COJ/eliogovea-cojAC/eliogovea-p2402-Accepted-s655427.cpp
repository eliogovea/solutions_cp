#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, len;
string str;
pair<int, int> arr[1005];
int pos[1005];
int cnt;

int main() {
	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		cin >> str;
		bool ok = false;
		for (int j = 0; j < len; j++)
			if (str[j] >= '1' && str[j] <= '9')
				arr[i] = make_pair(len - j, str[j] - '1'),
				ok = true;
        if (!ok) arr[i] = make_pair(900, 900);
        else cnt++;
	}

	sort(arr, arr + n);


	for (int i = 0, j = -1, last = -1; i < n; i++) {
		if (arr[i].first != last) j = arr[i - 1].first + 1, last = arr[i].first;
		arr[i].first = j;
	}

	for (int i = 0; i < n; i++)
		pos[arr[i].second] = arr[i].first;
	for (int i = 0; i < cnt; i++)
		cout << pos[i] << "\n";
}
