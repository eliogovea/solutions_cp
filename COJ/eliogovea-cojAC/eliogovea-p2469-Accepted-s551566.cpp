#include<iostream>
#include<map>
#include<set>
#define MAXN 2500
using namespace std;

int n,g;
string str;
map<string,int> M;
set<int> S;

int main()
{
    ios::sync_with_stdio(false);
    
	cin >> n;

	for(int i=1; i<=n; i++)
	{
		cin >> str;
		M[ str ]=i;
	}

	for(int i=1; i<=n; i++)
	{
		cin >> str;
		int idx = M[str];
		S.insert(idx);
		g+=distance( S.begin() , S.find(idx) );
	}

	cout << g << '/' << n*(n-1)/2 << endl;
}
