#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
char ch;
int v, nw, tot;
vector<int> seg, words;

int main() {
    cin >> str >> ch >> v;

    for (int i = 0; str[i];) {
        int cont = 0;
        while (str[i] == ch) {cont++; i++;}
        if (cont) seg.push_back(cont), tot += cont;
        else i++;
    }


    cin >> nw;
    while (nw--) {
        cin >> str;
        words.push_back(int(str.size()));
    }
    sort(seg.begin(), seg.end(), greater<int>());
    sort(words.begin(), words.end(), greater<int>());
    int p1 = 0, p2 = 0;
    while (p1 < seg.size() && p2 < words.size()) {
        while (p2 < words.size() && words[p2] > seg[p1]) p2++;
        if (p2 < words.size()) tot -= words[p2], p2++;
        p1++;
    }
    cout << tot * v << endl;
}
