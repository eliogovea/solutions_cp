#include<iostream>
#include<cstring>
using namespace std;

char a[100001];
int aux,n,l,r;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> a;
        l=strlen(a);
        aux=0;
        for(int i=l>8?l-8:0; i<l; i++)aux=10*aux+(a[i]-'0');
        r = (r + aux%128)%128;
    }
    cout << r << endl;
    return 0;
}
