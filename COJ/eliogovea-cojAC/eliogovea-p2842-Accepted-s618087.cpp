#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sf scanf
#define pf printf


const int MAXN = 10000000;

bool criba[MAXN + 5];

bool pal(int n) {
    if (criba[n]) return 0;
    int rev = 0, m = n;
    while (n) {
        rev = 10 * rev + n % 10;
        n /= 10;
    }
    return m == rev;
}

vector<int> v;
int tc, a, b;

int main() {
    for (int i = 2; i * i <= MAXN; i++)
        if (!criba[i])
            for (int j = i * i; j <= MAXN; j +=i)
                criba[j] = 1;
    v.push_back(2);
    for (int i = 3; i <= MAXN; i += 2)
        if (pal(i)) v.push_back(i);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a));
    }

}

