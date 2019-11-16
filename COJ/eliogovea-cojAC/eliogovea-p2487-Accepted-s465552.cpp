#include<iostream>
using namespace std;

int n,m,d[12881],i,j,mx;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    while(n--){
               cin >> i >> j;
               for(int k=m; k-i>=0; k--)d[k]=max(d[k],d[k-i]+j);
               }
    for(i=1;i<=m;i++)if(mx<d[i])mx=d[i];
    cout << mx << endl;
    return 0;
    }
