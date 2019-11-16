// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861B

#include <bits/stdc++.h>

using namespace std;

inline int nxt(int f, int a, int b, int c) {
    return ((((long long)a * f % c) + b) % c) + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    int f1, a, b, c;
    cin >> f1 >> a >> b >> c;

    map <int, int> f;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            f[x]++;
        }
    }

    vector <pair <int, int> > v;
    for (auto it : f) {
        v.push_back(make_pair(it.second, it.first));
    }

    vector <int> cd(v.size());
    cd[0] = f1;
    for (int i = 1; i < v.size(); i++) {
        cd[i] = nxt(cd[i - 1], a, b, c);
    }

    vector <pair <int, int> > w(v.size());
    for (int i = 0; i < v.size(); i++) {
        w[i].first = cd[i];
        w[i].second = i;
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    vector <int> answer(v.size());

    for (int i = 0; i < v.size(); i++) {
        answer[w[i].second] = v[i].second;
    }

    cout << v.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i + 1 < answer.size()) {
            cout << " ";
        }
    }
    cout << "\n";
}
