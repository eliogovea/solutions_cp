#include<iostream>
#include<cstdio>
#define MAXN 100000
using namespace std;

typedef string::iterator si;

struct trie
{
	bool fin;
	trie *next[27];
};

string w[MAXN];

void del(trie *x)
{
	for(int i=0; i<26; i++)
		if(x->next[i]!=NULL)
			del(x->next[i]);
	delete(x);
}

int n,sum;

int main()
{
	while(cin >> n)
	{
		trie *root = new trie();

		for(int i=0; i<n; i++)
		{
			cin >> w[i];
			trie *ptr = root;
			for(si it=w[i].begin(); it!=w[i].end(); it++)
			{
				int k=*it-'a'+1;
				if(ptr->next[k]==NULL)
					ptr->next[k]=new trie();
				ptr=ptr->next[k];
			}
			ptr->fin=1;
		}
		for(int i=0; i<n; i++)
		{
			trie *ptr = root;
			int cant=w[i].size();
			for(si it=w[i].begin(); it!=w[i].end(); it++)
			{
				int b=1,
				k=*it-'a'+1;
				if(ptr->fin)b=0;
				else for(int r=0; r<27; r++)
						if(ptr->next[r]!=NULL && r!=k)
						{
							b=0;
							break;
						}
				cant-=b;
				ptr=ptr->next[k];
			}
			sum+=cant;
		}

		char first=w[0][0];

		int mas=n;

		for(int i=1; i<n; i++)
            if(w[i][0]!=first)
            {
                mas=0;
                break;
            }

        sum+=mas;

		printf("%.2lf\n",(double)sum/(double)n);

		sum=0;

		del(root);
	}
}
