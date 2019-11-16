#include<iostream>
using namespace std;

int t;
long long n;
bool cero,uno;

int main()
{
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(n)
        {
            if(cero && uno)break;
            if(n&1)uno=1;
            else cero=1;
            n>>=1;
        }
        if(cero && uno)cout << "YES" << endl;
        else cout << "NO" << endl;
        cero=uno=0;
    }
    return 0;
}
