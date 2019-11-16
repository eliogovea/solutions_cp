// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174D

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

int n, d, c;
bool ca[55], cb[55];

int hashVal[55][55][55];
int xa[1000], xb[1000], xab[1000];

LD comb[55][55];

LD P[1000][1000];
LD invP[1000][1000];

void invert(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            invP[i][j] = 0.0;
        }
        invP[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(P[j][i]) > abs(P[id][i])) {
                id = j;
            }
        }
        for (int j = 0; j < n; j++) {
            swap(P[i][j], P[id][j]);
            swap(invP[i][j], invP[id][j]);
        }
        double x = P[i][i];
        for (int j = 0; j < n; j++) {
            P[i][j] /= x;
            invP[i][j] /= x;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double x = P[j][i];
                for (int k = 0; k < n; k++) {
                    P[j][k] -= P[i][k] * x;
                    invP[j][k] -= invP[i][k] * x;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> d >> c;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        ca[x] = true;
    }

    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        cb[x] = true;
    }

    int A = 0;
    int B = 0;
    int AB = 0;
    for (int i = 1; i <= n; i++) {
        if (ca[i] && !cb[i]) {
            A++;
        } else if (!ca[i] && cb[i]) {
            B++;
        } else if (ca[i] && cb[i]) {
            AB++;
        }
    }

    int curVal = 0;
    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int ab = 0; ab <= AB; ab++) {
                xa[curVal] = a;
                xb[curVal] = b;
                xab[curVal] = ab;
                hashVal[a][b][ab] = curVal++;
            }
        }
    }


    for (int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1.0;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int ab = 0; ab <= AB; ab++) {
                if (ab == AB && (a == A || b == B)) {
                    continue;
                }
                for (int da = 0; a + da <= A; da++) {
                    for (int db = 0; b + db <= B; db++) {
                        for (int dab = 0; ab + dab <= AB; dab++) {
                            if (d - da - db - dab < 0 || d - da - db - dab > n - (A - a) - (B - b) - (AB - ab)) {
                                P[hashVal[a][b][ab]][hashVal[a + da][b + db][ab + dab]] = 0.0;
                            } else {
                                P[hashVal[a][b][ab]][hashVal[a + da][b + db][ab + dab]] = comb[A - a][da] * comb[B - b][db] * comb[AB - ab][dab] * comb[n - (A - a) - (B - b) - (AB - ab)][d - da - db - dab] / comb[n][d];
                                //cerr << "-->>> " << hashVal[a][b][ab] << " " << hashVal[a + da][b + db][ab + dab] << " " << P[hashVal[a][b][ab]][hashVal[a + da][b + db][ab + dab]] << "\n";
                                //cerr << "--->> " << comb[A - a][da] << " " << comb[B - b][db] << " " << comb[] << "\n";
                            }

                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < curVal; i++) {
        for (int j = 0; j < curVal; j++) {
            if (i != j) {
                P[i][j] = -P[i][j];
            } else {
                P[i][j] = 1.0 - P[i][j];
            }
        }
    }

    invert(curVal);
    LD answer = 0.0;
    for (int i = 0; i < curVal; i++) {
        if (xab[i] == AB && (xa[i] == A || xb[i] == B)) {
            continue;
        }
        answer += invP[0][i];
    }
    cout.precision(15);
    cout << fixed << answer << "\n";
}
