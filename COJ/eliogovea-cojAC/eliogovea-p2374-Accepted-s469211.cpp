#include<iostream>
#include<cstring>
using namespace std;

char a[7],b[7];
long amax,amin,bmax,bmin;

int main(){
    cin >> a >> b;
    for(int i=0; i<strlen(a); i++){
            if(a[i]=='5'){amax=10*amax+6;amin=10*amin+5;}
            else if(a[i]=='6'){amax=10*amax+6;amin=10*amin+5;}
            else{amax=10*amax+(a[i]-'0');amin=10*amin+(a[i]-'0');}
            }
    for(int i=0; i<strlen(b); i++){
            if(b[i]=='5'){bmax=10*bmax+6;bmin=10*bmin+5;}
            else if(b[i]=='6'){bmax=10*bmax+6;bmin=10*bmin+5;}
            else{bmax=10*bmax+(b[i]-'0');bmin=10*bmin+(b[i]-'0');}
            }
            
    cout << amin+bmin << " " << amax+bmax << endl;
    return 0; 
    }
