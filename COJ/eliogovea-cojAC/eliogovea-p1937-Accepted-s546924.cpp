#include<iostream>
#include<cmath>
using namespace std;

unsigned long long n,s;
int i=1;

int main(){
    while(cin >> n && n)
    {
        s=(unsigned long long)ceil((3.0+sqrt(9.0+8.0*n))/2ll);
        cout << "Case " << i++ << ": " << s << endl;
    }
    return 0;
}