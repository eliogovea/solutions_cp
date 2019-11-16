#include<iostream>
#include<cmath>
using namespace std;
double l,t;
int c;
int main()
{
    cin >> c;
    while(c--)
    {
        cin >> l >> t;
        cout << (int)(log(t/l)/log(5.0/3.0)) << endl;
    }
    return 0;
}
