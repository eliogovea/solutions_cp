#include<iostream>
#include<vector>
using namespace std;

int n,m,a[15],j;
vector<int> v;

int main( ){
    std::ios::sync_with_stdio(0);
      cin>>n;
      for(int i=0; i<n; i++){
              int m;
              cin >> m;
              j=-1;
              while( m ){
                     a[++j]=m&1;
                     m>>=1;
                     }
              for(int k=0; k<15; k++)if(a[k])
              {
                  v.push_back(k);
                  a[k]=0;
              }

              for(int i=0; i<v.size()-1; i++)cout << v[i] << " ";
              cout << v[v.size()-1] << endl;
              v.clear();
              }
        return 0;
      }
