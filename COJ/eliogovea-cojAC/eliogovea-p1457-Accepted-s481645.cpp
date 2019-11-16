#include<iostream>
using namespace std;

long n,k;
unsigned long long ans;

int main()
{
    cin >> n >> k;
    ans=n*(n-1)*k/2;
    cout << ans << endl;
    return 0;
}
