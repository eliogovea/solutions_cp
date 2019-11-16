#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

string str;

typedef long long ll;

int n, sol;
const int MAXN = 1000000;
bool criba[MAXN + 5];
vector<int> p, v;


int main()
{
    int a = 2, sum = 1;
    v.push_back(0);
    while (sum <= MAXN) {
        v.push_back(sum);
        sum += a++;
    }

    for (int i = 2; i * i <= MAXN; i++)
        if (!criba[i])
            for (int j =  i * i; j <= MAXN; j += i)
                criba[j] = 1;
    for (int i = 3; i <= MAXN; i++)
        if (!criba[i]) p.push_back(i);
    while (cin >> n  && n) {
        sol = 1;
        int a = n;
        while (n % 2 == 0) n /= 2;
        for (int i = 0; p[i] * p[i] <= n; i++)
            if (n % p[i] == 0) {
                int cant = 0;
                while (n % p[i] == 0) {
                    n /= p[i];
                    cant++;
                }
                sol *= (cant + 1);
            }
        if (n > 1) sol *= 2;
        sol -= binary_search(v.begin(), v.end(), a);
        cout << sol  << endl;
    }
}
