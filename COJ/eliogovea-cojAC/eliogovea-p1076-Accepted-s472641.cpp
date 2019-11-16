#include<iostream>
#include<algorithm>
using namespace std;

char x[20];
int c,n,a[10000],b;

int main(){
    cin >> c;
    while(c--){
               b=0;
               cin >> n;
               for(int i=0; i<n; i++)cin >> x >> a[i];
               sort(a,a+n);
               for(int i=0; i<n; i++)b+=abs(a[i]-i-1);
               cout << b << endl;
               }
    return 0;
    }
