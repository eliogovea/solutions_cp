#include<iostream>
using namespace std;

const int pos[12][2] = { { 0, 4 }, { 1, 1 }, { 1, 3 }, { 1, 5 }, { 1, 7 },
						 { 2, 2 }, { 2, 6 }, { 3, 1 }, { 3, 3 }, { 3, 5 },
						 { 3, 7 }, { 4, 4 } };

char in[15][15];
int b[15];
bool mark[15],ok = false;

void f( int c )
{
    //cout << c << endl;
    //for( int i = 0; i < 5; i++ ) cout << in[i] << endl;
    //cout << endl;
    //system( "pause" );

	if( ok ) return;

	if( c == 12 )
	{
		int u,v;
		u = b[0] + b[2] + b[5] + b[7];
		v = b[0] + b[3] + b[6] + b[10];
		if( u != v ) return;
		v = b[1] + b[2] + b[3] + b[4];
		if( u != v ) return;
		v = b[7] + b[8] + b[9] + b[10];
		if( u != v ) return;
		v = b[1] + b[5] + b[8] + b[11];
		if( u != v ) return;
		v = b[4] + b[6] + b[9] + b[11];
		if( u != v ) return;

		for( int i = 0; i < 5; i++ ) cout << in[i] << endl;
		ok = true;
		return;
	}

	if( in[pos[c][0]][pos[c][1]] != 'x' )
		f( c + 1 );

	else for( char ch = 'A'; ch <= 'L'; ch++ )
			if( !mark[ch - 'A'] )
			{
				mark[ch - 'A'] = 1;
				in[pos[c][0]][pos[c][1]] = ch;
				b[c] = ch;
				f( c + 1 );
				in[pos[c][0]][pos[c][1]] = 'x';
				mark[ch - 'A'] = 0;
			}

}

int main()
{
	for( int i = 0; i < 5; i++ ) cin >> in[i];
	for( int i = 0; i < 12; i++ )
	{
		char ch = in[pos[i][0]][pos[i][1]];
		if( ch != 'x' )
		{
			b[i] = ch;
			mark[ch - 'A'] = 1;
		}
	}
	f( 0 );
}
