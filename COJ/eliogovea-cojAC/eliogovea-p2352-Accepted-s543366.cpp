#include<iostream>
#include<string>
#include<algorithm>
#define MAX 100000
using namespace std;

typedef string::iterator si;

struct trie
{
	bool fin;
	trie *next[11];
};

bool comp(const string &a, const string &b)
{
	return (a.size()!=b.size())?(a.size()<b.size()):(a<b);
}

void del(trie *x)
{
	for(int i=1; i<=10; i++)
		if(x->next[i]!=NULL)
			del(x->next[i]);
	delete(x);
}

int n,cas;
string w[MAX],sol;

int main()
{
	cin >> cas;
	while(cas--)
	{
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> w[i];

		sort(w,w+n,comp);
		trie *root = new trie();
		bool b=1;
		for(int i=0; i<n && b; i++)
		{
			trie *ptr = root;
			for(si it=w[i].begin(); it!=w[i].end() && b; it++)
			{
				int k = *it-'0'+1;
				if(ptr->next[k]==NULL)ptr->next[k]=new trie();
				ptr=ptr->next[k];
				if(ptr->fin)b=0;
			}
			ptr->fin=1;
		}
		if(b)cout << "YES" << endl;
		else cout << "NO" << endl;
		del(root);
	}
}
