#include <iostream>
using namespace std;

long long r;
unsigned long long rr;
float ans;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
            
            cin >> r;
            if(r<0)r*=-1;
            
            rr=2*r*r*r;
            ans=rr/3;
            cout << (long long)(rr/3);
            if(r%3==0)cout << ".000" << endl;
            else if(r%3==1)cout << ".667" << endl;
            else cout << ".333" << endl;            
            }
    return 0;
    }
