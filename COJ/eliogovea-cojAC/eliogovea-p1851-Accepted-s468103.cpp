#include<iostream>
using namespace std;

int h[100000],n,mx;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){cin >> h[i]; if(mx<h[i])mx=h[i];}
    for(int i=0; i<n; i++)cout << mx-h[i] << endl;
    return 0;
    }
