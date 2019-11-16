// 2016 USP Try-outs
// 101064H

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int BASE = 1000000000;

typedef vector <int> bigInt;

const bigInt ONE(1, 1);

bigInt mul(const bigInt &a, int k) {
    bigInt res(a.size(), 0);
    long long carry = 0;
    for (int i = 0; i < a.size(); i++) {
        carry += (long long)a[i] * k;
        res[i] = carry % BASE;
        carry /= BASE;
    }
    while (carry > 0) {
        res.push_back(carry % BASE);
        carry /= BASE;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector <pair <bigInt, int> > pa(1 << n);
    pa[0].first = ONE;
    pa[0].second = 0;

    for (int i = 1; i < (1 << n); i++) {
        int pos = 0;
        while (!(i & (1 << pos))) {
            pos++;
        }
        pa[i].first = mul(pa[i ^ (1 << pos)].first, a[pos]);
        pa[i].second = i;
    }
    sort(pa.begin(), pa.end());

    vector <bigInt> pb(1 << m);
    pb[0] = ONE;
    for (int i = 1; i < (1 << m); i++) {
        int pos = 0;
        while (!(i & (1 << pos))) {
            pos++;
        }
        pb[i] = mul(pb[i ^ (1 << pos)], b[pos]);
        int x = lower_bound(++pa.begin(), pa.end(), make_pair(pb[i], -1)) - pa.begin();
        if (x < pa.size() && pa[x].first == pb[i]) {
            cout << "Y\n";
            int mask = pa[x].second;
            vector <int> va;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    va.push_back(a[j]);
                }
            }
            vector <int> vb;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    vb.push_back(b[j]);
                }
            }
            cout << va.size() << " " << vb.size() << "\n";
            for (int j = 0; j < va.size(); j++) {
                cout << va[j];
                if (j + 1 < va.size()) {
                    cout << " ";
                }
            }
            cout << "\n";
            for (int j = 0; j < vb.size(); j++) {
                cout << vb[j];
                if (j + 1 < vb.size()) {
                    cout << " ";
                }
            }
            cout << "\n";
            exit(0);
        }
    }
    cout << "N\n";
}
