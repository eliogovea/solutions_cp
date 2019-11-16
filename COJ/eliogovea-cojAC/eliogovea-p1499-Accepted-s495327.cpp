#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

int n;
const int MAX=40000;
typedef unsigned long long ll;
bool sieve[MAX];
vector<ll>a;
vector<ll>b;
vector<ll>c;

bool primo(ll n){
     if(n==1)return 0;
     if(n==2 || n==3)return 1;
     if(n%2==0)return 0;
     for(ll i=3; i*i<=n; i+=2)
             if(n%i==0)return 0;
     return 1;
     }

int main(){
    for(int i=2; i<=MAX; i++)sieve[i]=1;
    
    for(int i=2; i*i<=MAX; i++)
            if(sieve[i])for(int j=i*i; j<=MAX; j+=i)sieve[j]=0;
            
    for(int i=2; i<=MAX; i++)if(sieve[i])a.push_back(i);
    
    for(int i=0; i<a.size()-1; i+=2)
            b.push_back(pow(10.0,(int)log10(a[i+1])+1)*a[i]+a[i+1]);

    for(int i=0; i<b.size(); i++)
            if(primo(b[i]))c.push_back(b[i]);
            
    cin >> n;
    cout << c[n-1] << endl;
    return 0;
    }
