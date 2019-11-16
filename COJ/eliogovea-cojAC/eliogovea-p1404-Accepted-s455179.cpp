#include<iostream>
using namespace std;

long c[151][151],sol[151],n,m;

int main(){
    for(int i=0; i<151; i++)c[i][0]=c[i][i]=1;
    for(int i=1; i<151; i++)
    for(int j=1; j<i; j++)c[i][j]=(c[i-1][j]%1000003+c[i-1][j-1]%1000003)%1000003;
    
    sol[0]=1;
    for(int i=1; i<151; i++)
    for(int j=1; j<=i; j++)sol[i]=(sol[i]+(c[i][j]*sol[i-j])%1000003)%1000003;
    
    cin >> n;
    while(n--){
               cin >> m;
               cout << sol[m] << endl;
               }
    return 0;
    }