/// Copa UNISS - I

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long
#define MAXN 1000000

struct pt
{
    int x, y;
    pt (int a, int b) : x(a), y(b){}
    bool operator < (const pt &a) const
    {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

struct recta
{
    ll a, b, c;
    recta(ll x, ll y, ll z)
    {
        a = x; b = y; c = z;
    }
    bool operator < (const recta &r) const
    {
        if (a != r.a) return a < r.a;
        if (b != r.b) return b < r.b;
        return c < r.c;
    }
};

ll x[1010], y[1010];
map<recta, set<int> > m;

int main(){

    ll n, sol = 0;
    scanf("%lld", &n);
    map<pt, int> S;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
        S[pt(x[i], y[i])]++;
        for (int j = 0; j < i; j++)
        {
            ll aa = y[i] - y[j];
            ll bb = x[j] - x[i];
            ll cc = y[j] * (x[i] - x[j]) - x[j] * (y[i] - y[j]);

            if (aa < 0ll)
            {
                aa *= -1ll;
                bb *= -1ll;
                cc *= -1ll;
            }
            else if (aa == 0ll)
            {
                if (bb < 0ll)
                {
                    bb *= -1ll;;
                    cc *= -1ll;
                }
                else if (bb == 0ll)
                    cc *= -1ll;
            }

            if (!(aa == 0ll && bb == 0ll && cc == 0ll))
            {
                ll g = __gcd(labs(aa), __gcd(labs(bb), labs(cc)));
                aa /= g;
                bb /= g;
                cc /= g;
                recta r(aa, bb, cc);
                m[r].insert(i);
                m[r].insert(j);
                sol = max(sol, (ll)m[r].size());
            }
        }
    }
    for (map<pt, int>::iterator it = S.begin(); it != S.end(); it++)
        sol = max(sol, (ll)it->second);
    printf("%lld\n", sol);
}

