#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXS = 1000005, alph = 26;

int N;
string w[10005];

bool cmp(const string &a, const string &b) {
    return a.size() < b.size();
}

struct vertex {
	int fin;
	int fail;
	int link;
	int next[alph];
	vertex() {
		fin = fail = link = -1;
		for (int i = 0; i < alph; i++) next[i] = -1;
	}
} T[MAXS];

int states;

void add(const string &s, int p) {
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		char c = s[i] - 'a';
		if (T[cur].next[c] == -1)
			T[cur].next[c] = states++;
		cur = T[cur].next[c];
	}
	T[cur].fin = p;
}

void buildTrie() {
	for (int i = 0; i < states; i++)
		T[i] = vertex();
	states = 1;
	for (int i = 0; i < N; i++)
		add(w[i], i);
}

queue<int> Q;

void buildAC() {
	for (int i = 0; i < alph; i++)
		if (T[0].next[i] == -1) T[0].next[i] = 0;
		else {
			T[T[0].next[i]].fail = 0;
			Q.push(T[0].next[i]);
		}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < alph; i++)
			if (T[cur].next[i] != -1) {
				int fail = T[cur].fail;
				int next = T[cur].next[i];
				while (T[fail].next[i] == -1)
					fail = T[fail].fail;
				fail = T[fail].next[i];
				T[next].fail = fail;
				if (T[fail].fin != -1) T[next].link = fail;
				else T[next].link = T[fail].link;
				Q.push(next);
			}
	}
}

int dp[MAXS];

int solve() {
	int ret = 1;
	for (int i = 0; i < N; i++) dp[i] = 1;
	for (int i = 0; i < N; i++) {
		const string &s = w[i];
		int cur = 0;
		for (int j = 0; s[j]; j++) {
			char c = s[j] - 'a';
			while (T[cur].next[c] == -1)
                cur = T[cur].fail;
			cur = T[cur].next[c];
			if (T[cur].fin != -1 && T[cur].fin != i)
				dp[i] = max(dp[i], dp[T[cur].fin] + 1);
			for (int k = T[cur].link; k != -1; k = T[k].link)
                if (T[k].fin != i)
                    dp[i] = max(dp[i], dp[T[k].fin] + 1);
		}
		ret = max(ret, dp[i]);
	}
	return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	while (cin >> N && N) {
		for (int i = 0; i < N; i++)
			cin >> w[i];
        sort(w, w + N, cmp);
		buildTrie();
		buildAC();
		cout << solve() << "\n";
	}
}
