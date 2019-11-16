#include<iostream>
using namespace std;

int v[5],n,cand,reg,mx,mxp,x;

int main(){
    cin >> n;
    while(n--){
               cin >> cand >> reg;
               for(int i=0; i<cand; i++)v[i]=0;
               mx=0;mxp=0;
               while(reg--)for(int i=0; i<cand; i++){cin >> x; v[i]+=x;}
               for(int i=0; i<cand; i++)if(mx<v[i]){mx=v[i];mxp=i+1;}
               cout << mxp <<endl;
               }
    return 0;
    }
