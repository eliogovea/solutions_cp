#include<iostream>
#include<map>
using namespace std;

long long x,ac,cl,lu[100],n,ans[100];

int main()
{
    cin >> cl;

    map<long long,int> S;

    for(int i=0; i<cl; i++)
        cin >> lu[i];

    for(cin >>n ;n--;)
    {
        S[ac]++;
        cin >> x;
        ac+=x;

        for(int i=0; i<cl; i++)
            if( S[ac-lu[i]]>0 )
                ans[i]+=S[ac-lu[i]];
    }

    for(int i=0; i<cl; i++)
        cout << ans[i] << endl;

    return 0;
}
