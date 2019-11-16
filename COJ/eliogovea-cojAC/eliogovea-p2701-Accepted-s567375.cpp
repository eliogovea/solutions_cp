#include<iostream>
using namespace std;

string word;

int main()
{
	int dif = 'Z' - 'A' + 1;

	cin >> word;
	int sum = 0;
	for( int i = 0; word[i]; i++ ) sum += word[i] - 'A' + 1;

	int l1 = sum / 2;
	int l2 = sum - sum / 2;

	while( l1 - dif > 0 )
	{
		cout << 'Z';
		l1 -= dif;
	}
	char c = char( l1 ) + 'A' - 1;
	cout << c << " ";

	while( l2 - dif > 0 )
	{
		cout << 'Z';
		l2 -= dif;
	}
	c = char( l2 ) + 'A' - 1;
	cout << c << endl;
}
