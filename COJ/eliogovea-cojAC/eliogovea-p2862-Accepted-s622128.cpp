#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

typedef long long ll;

bool criba[MAXN + 5];
vector<ll> p, aux;
ll c[MAXN], tn, n, sol;

int main() {
    for (int i = 2; i * i <= MAXN; i++)
        if (!criba[i])
            for (int j = i * i; j <= MAXN; j += i)
                criba[j] = 1;
    p.push_back(2);
    for (int i = 3; i <= MAXN; i += 2)
        if (!criba[i]) p.push_back(i);

    scanf("%lld", &tn);
    for (int i = 0; i < tn; i++) {
        scanf("%lld", &n);
        aux.clear();
        for (int i = 0; p[i] * p[i] <= n; i++)
            if (n % p[i] == 0) {
                aux.push_back(p[i]);
                while (n % p[i] == 0) n /= p[i];
            }
        if (n > 1ll) aux.push_back(n);
        int s = aux.size();
        for (int i = 1; i < 1 << s; i++) {
            ll cant = 0, prod = 1ll;
            for (int j = 0; j < s; j++)
                if (i & (1 << j)) cant++, prod *= aux[j];
            if (cant & 1ll) sol += c[prod];
            else sol -= c[prod];
            c[prod]++;
        }
    }
    printf("%lld\n", tn * (tn - 1ll) / 2ll - sol);

}
