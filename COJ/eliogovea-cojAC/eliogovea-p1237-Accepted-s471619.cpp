#include<iostream>
#include<algorithm>
using namespace std;

long a,b,c;

int main()
{
    while(cin >> a >> b)
    {
        if(a==0 && b==0)break;
        c=min(2*a-b,2*b-a);
        cout << c << endl;
    }
return 0;
}
