/// Copa UNISS - G

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

int main(){
    ll p, g;
    while (scanf("%lld", &p) && p)
    {
        scanf("%lld", &g);
        bool b = true;
        ll r;
        while (g)
        {
            r = g % p;
            if (r > 1)
            {
                b = false;
                break;
            }
            g /= p;
        }
        printf("%s\n", b ? "YES" : "NO");
    }
}
