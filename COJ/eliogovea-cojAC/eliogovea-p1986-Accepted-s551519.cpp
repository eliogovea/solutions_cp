#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#define MAXN 50010
using namespace std;

int n;
int a,b;
pair<int,int> cow[MAXN];
map<int,int> ID,aux;
int main()
{
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		scanf("%d%d",&cow[i].first,&cow[i].second);
		ID[ cow[i].second ]++;
	}

	if(ID.size()==1)
    {
        printf("1\n");
        return 0;
    }

	sort(cow+1,cow+n+1);

	int i=1,j=1;
	int mn=1000000007;

	aux[ cow[1].second ]++;

	while(i<=n)
    {
        if( aux.size() == ID.size() )
		{
			mn = min( mn , cow[i].first - cow[j].first );
			aux[ cow[j].second ]--;
			if(aux[ cow[j].second ] == 0)
				aux.erase( aux.find( cow[j].second ) );
			j++;
		}

		else if( i < n )
			aux[ cow[++i].second ]++;

		else i++;
    }

	printf("%d\n",mn);
}
