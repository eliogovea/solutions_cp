#include<iostream>
#include<algorithm>
using namespace std;

int n[90],N,B,s;
bool b[91];

int main(){
    b[0]=1;
    while(cin >> N >> B){
              if(N==0 && B==0)break;s=0;
              
              for(int i=0; i<B; i++)cin >> n[i];
              
              for(int i=1; i<=N; i++)b[i]=0;
              
              for(int i=0; i<B-1; i++)
              for(int j=i+1; j<B; j++)b[abs(n[i]-n[j])]=1;

              for(int i=1; i<=N; i++)if(b[i])s++;

              if(s==N)cout << "Y" << endl;
              else cout << "N" << endl;
              }
    return 0;
    }
