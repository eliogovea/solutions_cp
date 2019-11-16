#include<iostream>
#define mod 1000000000
using namespace std;

int cas;
long long a,b,sol;

int main()
{
	for( cin >> cas; cas--; )
	{
		cin >> a >> b;
		a %= mod;
		sol = 1;
		while( b )
		{
			if( b & 1 )sol = ( sol * a ) % mod;
			a = ( a * a ) % mod;
			b >>= 1;
		}
		cout << sol << endl;
	}
}
