#include<iostream>
using namespace std;
int h[500],t,n;
bool b[45001];

int main(){
    cin >> t >> n;
    b[0]=1;
    for(int i=0; i<n; i++)cin >> h[i];
    
    for(int i=0; i<n; i++)
    for(int j=t-h[i]; j>=0; j--)b[j+h[i]]|=b[j];
    
    for(int i=t; i>=0; i--)if(b[i]){cout << i << endl;break;}
    return 0;
    }
