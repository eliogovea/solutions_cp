#include<iostream>
#include<algorithm>
using namespace std;

int n,a[8],b[8],ii,jj,s,mx;

int main(){
    cin >> n;
    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++)cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    
    for(int i=0; i<n; i++)s+=a[i]*b[n-1-i];
    
    cout << s << endl;
    
    return 0;
    
    }
