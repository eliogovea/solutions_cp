#include<iostream>
using namespace std;

int a[3][2];

int main(){
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1] >> a[2][0] >> a[2][1];
    
    if(a[0][0]==a[1][0])cout << a[2][0] << " ";
    else if(a[0][0]==a[2][0])cout << a[1][0] << " ";
    else if(a[1][0]==a[2][0])cout << a[0][0] << " ";
    
    if(a[0][1]==a[1][1])cout << a[2][1] << endl;
    else if(a[0][1]==a[2][1])cout << a[1][1] << endl;
    else if(a[1][1]==a[2][1])cout << a[0][1] << endl;
    return 0;
    }
