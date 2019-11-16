#include<iostream>
using namespace std;

int mx[10001],c,m,n,p,t,mxx;

int main(){
    cin >> c;
    while(c--){
               mxx=0;
               for(int i=0; i<=m; i++)mx[i]=0;
               cin >> m >> n;
               while(n--){
                          cin >> p >> t;
                          for(int i=t; i<=m; i++)mx[i]=max(mx[i],mx[i-t]+p);
                          }
               for(int i=m; i; i--)if(mxx<mx[i])mxx=mx[i];
               cout << mxx << endl;
               }
    return 0;
    }
