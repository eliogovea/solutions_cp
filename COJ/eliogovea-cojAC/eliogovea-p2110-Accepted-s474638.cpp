#include<iostream>
using namespace std;

int n,m,l=0,b[33],c[33],nb,pot=1;

int main(){
    cin >> n;
    
    while(n){b[l++]=n%2;n/=2;}
    
    c[l-1]=b[l-1];
    
    for(int i=l-2; i>=0; i--){
            /*if(b[i] && c[i+1])c[i]=0;
            else if(b[i] && !c[i+1])c[i]=1;
            else if(!b[i] && c[i+1])c[i]=1;
            else if(!b[i] && !c[i+1])c[i]=0;*/
            c[i]=b[i]^c[i+1];
            }
    for(int i=0; i<l; i++){
            nb+=c[i]*pot;
            pot*=2;
            }
            
    cout << nb << endl;
    return 0;
    }
