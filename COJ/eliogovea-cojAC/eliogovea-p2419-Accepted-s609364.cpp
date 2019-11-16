#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator () (const string &a, const string &b) const {
        for (int i = 0; a[i] && b[i]; i++)
            if (a[i] != b[i]) return a[i] > b[i];
        return a.size() < b.size();
    }
};

priority_queue<string, vector<string>, cmp> Q;



int tc, n;
string aux, sol, aux1;

int main() {
	cin.sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
		cin >> n;
		sol = "";
		for (int i = 0; i < n; i++) {
			cin >> aux;
			Q.push(aux);
		}
		while (!Q.empty()) {
			aux = Q.top();
			Q.pop();
			sol += aux[0];
			if (aux.size() > 1) {
				aux1.clear();
				for (int i = 1; aux[i]; i++) aux1 += aux[i];
				Q.push(aux1);
			}
		}
		cout << sol << endl;
	}

}
