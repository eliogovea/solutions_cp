#include<iostream>
using namespace std;

long sd[501];
int c,n;

int main(){
    for(int i=1; i<501; i++){
            for(int j=i; j<501; j+=i)sd[j]+=i;
            sd[i]-=i;
            }
    cin >> c;
    while(c--){
               cin >> n;
               if(sd[n]<n)cout << "Deficient" << endl;
               else if(sd[n]==n)cout << "Perfect" << endl;
               else cout << "Abundant" << endl;
               }
    return 0;
    }
