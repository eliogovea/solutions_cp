#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;

unsigned long n;

int main()
{
    while(cin >> n)
    {
        bitset<32>b(n);
        vector<bool>v;
        for(int i=0; i<32; i++)
            v.push_back(b[i]);

        reverse(v.begin(),v.end());
        next_permutation(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=0; i<32; i++)
            b[i]=v[i];

        cout << b.to_ulong() << endl;
    }
    return 0;
}
