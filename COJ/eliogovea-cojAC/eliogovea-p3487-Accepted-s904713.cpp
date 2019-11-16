#include <bits/stdc++.h>

using namespace std;

const int N = 20;

bool fila[N][N], col[N][N], cuadro[N][N][N];

int ans[N][N];

bool ok = false;

void fill(int x, int y) {
    if (ok) {
        return;
    }
	if (x == 9) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 3; j < 6; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 6; j < 9; j++) {
				cout << ans[i][j];
				if (j < 8) cout << " ";
			}
			cout << "\n";
		}
		cout << "------+-------+------\n";
		for (int i = 3; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 3; j < 6; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 6; j < 9; j++) {
				cout << ans[i][j];
				if (j < 8) cout << " ";
			}
			cout << "\n";
		}
		cout << "------+-------+------\n";
		for (int i = 6; i < 9; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 3; j < 6; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "| ";
			for (int j = 6; j < 9; j++) {
				cout << ans[i][j];
				if (j < 8) cout << " ";
			}
			cout << "\n";
		}
		ok = true;
		return;
	}
	if (ans[x][y]) {
		if (y == 8) {
			fill(x + 1, 0);
		} else {
			fill(x, y + 1);
		}
	} else {
		for (int i = 1; i <= 9; i++) {
			if (!fila[x][i] && !col[y][i] && !cuadro[x / 3][y / 3][i]) {
				ans[x][y] = i;
				fila[x][i] = true;
				col[y][i] = true;
				cuadro[x / 3][y / 3][i] = true;
				if (y == 8) {
					fill(x + 1, 0);
				} else {
					fill(x, y + 1);
				}
				ans[x][y] = 0;
				cuadro[x / 3][y / 3][i] = false;
				col[y][i] = false;
				fila[x][i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char ch;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
	}
	string s;
	cin >> s;
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
	}
	cin >> s;
	for (int i = 6; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
				ans[i][j] = ch - '0';
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
	}

	/*for (int i = 0; i < 9; i++) {
        for (int j = 0;j < 9; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
	}*/

	fill(0, 0);
}
