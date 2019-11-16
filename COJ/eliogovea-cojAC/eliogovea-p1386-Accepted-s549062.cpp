#include<cstdio>
#include<vector>
using namespace std;

int P,Q;
vector<int> VP,VQ;
vector<int>::iterator i1,i2;

int main()
{
	scanf("%d%d",&P,&Q);

	for(int i=1; i<=P; i++)
		if(!(P%i))VP.push_back(i);
	for(int i=1; i<=Q; i++)
		if(!(Q%i))VQ.push_back(i);

	for(i1=VP.begin(); i1!=VP.end(); i1++)
		for(i2=VQ.begin(); i2!=VQ.end(); i2++)
			printf("%d %d\n",*i1,*i2);
}
