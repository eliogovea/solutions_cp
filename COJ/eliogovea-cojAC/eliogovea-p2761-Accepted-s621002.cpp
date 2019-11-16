#include <iostream>
#include <algorithm>

using namespace std;

int n, sol;
string ini, fin;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ini;
        int vini = (ini[0] - 'A' + 1 + ini[1] - '0') & 1;
        if (vini) sol++;
        else sol--;
    }
    cout << abs(sol) << endl;
}
