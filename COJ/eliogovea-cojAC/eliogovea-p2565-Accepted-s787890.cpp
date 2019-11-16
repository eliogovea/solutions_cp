#include <bits/stdc++.h>

using namespace std;

int a, b;
int first[10005];
int ans[10005];

void solve(int a, int b) {
    int pe = a / b;
    a %= b;
    first[a] = 1;
    a *= 10;
    int beg = -1;
    int end = -1;
    for (int i = 0; i < b; i++) {
        first[i] = -1;
    }
    first[::a % ::b] = 1;
    for (int i = 1; i <= b + 1; i++) {
        ans[i] = a / b;
        a %= b;
        //cout << i << " " << a << "\n";
        if (first[a] != -1) {
            if (beg == -1) {
                //cout << "------" << a << " " << first[a] << "\n";
               beg = first[a];
               end = i;
            }
        } else {
            first[a] = i + 1;
        }
        a *= 10;
    }
    //cout << beg << " " << end << "\n";
    if (beg == -1) {
        beg = 1;
    }
    cout << end - beg + 1 << " ";
    cout << ::a / ::b << ".";
    for (int i = 1; i <= 50; i++) {
        if (beg == i) {
            cout << "(";
        }
        cout << ans[i];
        if (end == i) {
            cout << ")";
            break;
        }
    }
    if (end > 50) {
        cout << "...)";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(false);
    //freopen("dat.txt", "r", stdin);
    while (cin >> a >> b) {
        solve(a, b);
    }
}