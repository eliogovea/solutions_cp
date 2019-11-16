#include<iostream>
using namespace std;
int t;
long long n;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (n*n*n*n - 6*n*n*n+ 23*n*n - 18*n + 24)/24 << endl;
    }
    return 0;
}
