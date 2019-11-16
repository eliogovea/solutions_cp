#include<iostream>
#include<algorithm>
using namespace std;

int n,a[300000],t=1,mx;

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++)cin >> a[i];
    
    sort(a,a+n);
    
    mx=a[n-1]+1;
    
    for(int i=n-2; i>=0; i--){
            if(mx<a[i]+n-i)mx=a[i]+n-i;
            if(a[i]+n>=mx)t++;
            }
    
    cout << t << endl;
    return 0;
    }
