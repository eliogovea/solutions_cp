#include<iostream>
#include<algorithm>
using namespace std;

string num,aux;

int main()
{
	cin >> num;
	aux=num;

	next_permutation(aux.begin(), aux.end());

	if(aux>num)cout << aux;
	else cout << '0';
}
