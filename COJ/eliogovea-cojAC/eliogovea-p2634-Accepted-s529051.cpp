#include<iostream>
using namespace std;

int m[12];
int n,cant,x;
char c;

int main()
{
    for(cin >> cant; cant--;)
    {
        cin >> n >> n >> c >> n >> c >> x;
        m[n-1]++;
    }
    for(int i=0; i<12; i++)
        cout << i+1 << " " << m[i] << endl;
}
