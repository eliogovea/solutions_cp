#include<iostream>
using namespace std;

typedef unsigned long long ull;

int a,b;

void f(ull a, ull b)
{
    if(!(a%b))
    {
        cout << a/b-1 << ",1]" << endl;
        return;
    }
    cout << a/b << ',';
    f(b,a%b);
}

int main()
{
	while(cin >> a >> b && (a||b))
	{
	    cout << a << '/' << b  << '=' <<'[';
	    f(a,b);
	}
}
