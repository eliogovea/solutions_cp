#include<iostream>
using namespace std;

int n,m,w,c,tc,mx[1001],mxx,total;

int main(){
    cin >> tc;
    while(tc--){
                cin >> n >> m;
                for(int i=0; i<=m; i++)mx[i]=0;mxx=0;
                while(n--){
                           cin >> w >> c;
                           for(int i=m; i>=w; i--)mx[i]=max(mx[i],mx[i-w]+c);
                           }
                for(int i=m; i>=0; i--)if(mxx<mx[i])mxx=mx[i];
                total+=mxx;
                }
    cout << total << endl;
    return 0;
    } 
