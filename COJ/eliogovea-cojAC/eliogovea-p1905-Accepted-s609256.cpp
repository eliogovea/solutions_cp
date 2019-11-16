#include <iostream>
#include <sstream>
using namespace std;
#include <vector>
int n;
string line, aux;
vector<string> v;

int main() {
	cin >> n;
	getline(cin, line);
	while (n--) {

		getline(cin, line);

		for (int i = 0; line[i]; i++) {
			if (line[i] == ' ') {
				v.push_back(aux);
				aux = "";
			}
			else aux += line[i];
		}
		v.push_back(aux);
		aux = "";
		cout << v[0][0] << v[0][1];

		for (int i = v.size() - 1; i >= 1; i--) {
			cout << v[i];
			if (i != 1) cout << '*';
		}

		cout << v[0][2] << v[0][3] << endl;
		v.clear();
	}
}
