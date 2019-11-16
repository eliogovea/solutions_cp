#include <iostream>
//#include <cstdio>
using namespace std;

const int MAXN = 25;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int tc, r, c, mark[MAXN][MAXN], id;
int bin['Z' - 'A' + 5][7];
int code[MAXN][MAXN];
string str;

int main() {
	//freopen("e.in", "r", stdin);
	for (int i = 'A', ind; i <= 'Z'; i++) {
		int x = i - 'A' + 1, p = x;
		ind = 4;
		while (x) {
			bin[p][ind--] = (x & 1);
			x >>= 1;
		}
	}
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		id++;
		cin >> r >> c;
		getline(cin, str);
		//cout << str << '\n';
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				code[i][j] = 0;
		int x = 0, y = 0, d = 0;
		for (int i = 1; str[i]; i++) {
			int b = str[i] - 'A' + 1;
			for (int j = 0; j < 5; j++) {
        //cout << y << ' ' << x << ' ' << bin[b][j] << '\n';
				code[x][y] = bin[b][j];
				mark[x][y] = id;
				if (j == 4 && !str[i + 1]) break;
				int nx = x + dx[d];
				int ny = y + dy[d];
				while (nx < 0 || nx >= r || ny < 0 || ny >= c || mark[nx][ny] == id) {
					d = (d + 1) % 4;
					nx = x + dx[d];
					ny = y + dy[d];
				}
        x = nx;
        y = ny;
			}
		}
		cout << cas << ' ';
		for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cout << code[i][j];
    cout << '\n';
	}
}
