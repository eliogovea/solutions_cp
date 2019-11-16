#include<iostream>
using namespace std;

int c,n,m,a[102][102],mx;

int main(){
    cin >> c;
    while(c--){

               for(int i=0; i<102; i++)
               for(int j=0; j<102; j++)a[i][j]=0;
               mx=0;

               cin >> n  >> m;

               for(int i=1; i<=n; i++)
               for(int j=1; j<=m; j++)cin >> a[i][j];

               for(int i=1; i<=n; i++)
               for(int j=1; j<=m; j++)a[i][j]+=max(a[i-1][j-1],max(a[i-1][j],a[i-1][j+1]));

               for(int i=1; i<=m; i++)if(mx<a[n][i])mx=a[n][i];

               cout << mx << endl;
               }
    return 0;
    }