
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

int v['Z' + 1];

int main()
{
    v['I'] = 1;
    v['V'] = 5;
    v['X'] = 10;
    v['L'] = 50;
    v['C'] = 100;
    v['D'] = 500;
    v['M'] = 1000;
    int n;
    char str[100];
    for (scanf("%d", &n); n--;)
    {
        scanf("%s", str);
        int l = strlen(str);
        int x = v[ str[l - 1] ];
        for (int i = l - 1; i > 0; i--)
            if (v[str[i]] > v[str[i - 1]]) x -= v[str[i - 1]];
            else x += v[ str[i - 1] ];
        printf("%s %d\n", (x % 3 == 0) ? "YES" : "NO", x);
    }
}
