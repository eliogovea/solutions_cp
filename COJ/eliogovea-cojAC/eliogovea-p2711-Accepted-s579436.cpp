#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
vector<pair<int,int> > v;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		v.push_back(make_pair(x, i));
	}

	sort(v.begin(),v.end(),greater<pair<int, int> >() );

	for (int i = 0; i < n; i++)
		printf("%d\n", v[i].second);
}
