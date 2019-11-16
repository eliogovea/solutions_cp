#include<iostream>
using namespace std;

bool s[51];
unsigned long long a[51];
int n;

int main(){
    s[0]=1;
    s[1]=1;
    for(int i=2; i*i<=50; i++)if(!s[i])for(int j=i*i; j<=50; j+=i)s[j]=1;
    a[2]=2;
    for(int i=3; i<51; i++){
            if(!s[i])a[i]=i*a[i-1];
            else a[i]=a[i-1];
            }
    while(cin >> n && n!=0)cout << a[n] << endl;
    }
