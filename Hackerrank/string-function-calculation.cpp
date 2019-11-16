#include <bits/stdc++.h>

using namespace std;

const int SIZE = 2 * 100 * 1000 + 10;

int length[SIZE];
int suffix_link[SIZE];
map <char, int> go[SIZE];

int size;
int last;


inline int get_new(int _length) {
    int res = size++;
    length[res] = _length;
    suffix_link[res] = -1;
    go[res] = map <char, int> ();
    return res;
}

inline int get_clone(int node, int _length) {
    int res = size++;
    length[res] = _length;
    suffix_link[res] = suffix_link[node];
    go[res] = go[node];
    return res;
}

inline void init() {
    size = 0;
    last = get_new(0);
}

int add(char c) {
    int p = last;
    int cur = get_new(length[p] + 1);
    while (p != -1 && go[p].find(c) == go[p].end()) {
        go[p][c] = cur;
        p = suffix_link[p];
    }
    if (p == -1) {
        suffix_link[cur] = 0;
    } else {
        int q = go[p][c];
        if (length[p] + 1 == length[q]) {
            suffix_link[cur] = q;
        } else {
            int clone = get_clone(q, length[p] + 1);
            suffix_link[cur] = suffix_link[q] = clone;
            while (p != -1 && go[p][c] == q) {
                go[p][c] = clone;
                p = suffix_link[p];
            }
        }
    }
		last = cur;
    return cur;
}

int value[SIZE];
int sorted[SIZE];
int cnt[SIZE];

int main() {
    string t;
    cin >> t;
    
    int n = t.size();
    
    init();
    
    for (int i = 0; i < n; i++) {
        add(t[i]);
        value[last]++;
    }
    
    for (int i = 0; i < size; i++) {
        cnt[length[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < size; i++) {
        sorted[--cnt[length[i]]] = i;
    }
    for (int i = size - 1; i > 0; i--) {
        value[suffix_link[sorted[i]]] += value[sorted[i]];
    }
    
    long long answer = 0;
    for (int i = 0; i < size; i++) {
        answer = max(answer, (long long)value[i] * length[i]);
    }
    cout << answer << "\n";
}
