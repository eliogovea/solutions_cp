#include <iostream>

using namespace std;

string str;

typedef long long ll;

const ll mod = 1000000007;
ll n;

int main()
{
    cin >> str;

    for (int i = 0; ;) {
        if (str[i] == '0' || str[i] == '1') {
            while (str[i] == '0' || str[i] == '1')
                n = ((2 * n) % mod + str[i] - '0') % mod, i++;
            cout << n;
            n = 0ll;
        }
        else if (!str[i]) break;
        else cout << str[i], i++;
    }
}