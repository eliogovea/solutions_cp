#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int n;
string words[MAXN];
vector<int> G['z' + 10], letras;
vector<pair<int, char> > v;
bool mark['z' + 10]['z' + 10], let['z' + 10];
int tot['z' + 10]/*, lev['z' + 10]['z' + 10]*/;
bool no_order = false;

int dfs(int root, int act/*, int l*/)
{
    ///lev[root][act] = l;
    mark[root][act] = 1;
	for (int i = 0; i < G[act].size(); i++)
    {
        if (mark[root][G[act][i]]
			&& G[act][i] == root) no_order = true;
		else if (!mark[root][G[act][i]])
		{
			tot[root]++;
			dfs(root, G[act][i]/*, l + 1*/);
		}
    }
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> words[i];
		for (int j = 0; words[i][j]; j++)
			if (!let[words[i][j]])
			{
				letras.push_back(words[i][j]);
				let[words[i][j]] = 1;
			}
		for (int j = 0; j < i; j++)
			for (int k = 0; words[i][k] && words[j][k]; k++)
				if (words[i][k] != words[j][k])
				{
					G[words[j][k]].push_back(words[i][k]);
					break;
				}
	}
	for (int i = 0; i < letras.size(); i++)
		dfs(letras[i], letras[i]/*, 0*/),
		v.push_back(make_pair(tot[letras[i]], char(letras[i])));
	bool sol = true;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		if (v[i].first != i)
		{
			sol = false;
			break;
		}
	if (no_order) cout << "!";
	else if (sol) for (int i = v.size() - 1; i >= 0; i--) cout << v[i].second;
	else cout << "?";
}
