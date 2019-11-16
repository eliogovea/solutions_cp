#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

ll a, b, p, s, pp;
ll sol[1000], ind;

int main()
{
    while (cin >> a >> b >> p)  {
        a--;
        s = 0;
        pp = p;
        while (true) {
            s += ( b / pp - a / pp );
            if (pp > b / p + b % p) {
                //cout << pp << endl;
                break;
            }
            pp *= p;
        }

        while (s) {
            sol[ind++] = s % 8ll;
            s /= 8ll;
        }
        if (!ind) printf("0");
        for (int i = ind - 1; i >= 0; i--)
            cout << sol[i];
        printf("\n");
        ind = 0;
    }
}
