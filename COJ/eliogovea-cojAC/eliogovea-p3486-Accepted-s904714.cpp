#include <bits/stdc++.h>

using namespace std;

const int N = 20;

bool fila[N][N], col[N][N], cuadro[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char ch;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			if (ch != '*') {
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
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
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
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
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 3; j < 6; j++) {
			cin >> ch;
			if (ch != '*') {
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
		cin >> ch;
		for (int j = 6; j < 9; j++) {
			cin >> ch;
			if (ch != '*') {
				fila[i][ch - '0'] = true;
				col[j][ch - '0'] = true;
				cuadro[i / 3][j / 3][ch - '0'] = true;
			}
		}
	}
	bool ok = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (!fila[i][j] || !col[i][j]) {
				ok = false;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k <= 9; k++) {
				if (!cuadro[i][j][k]) {
					ok = false;
				}
			}
		}
	}
	cout << (ok ? "CORRECT" : "WRONG") << "\n";
}
