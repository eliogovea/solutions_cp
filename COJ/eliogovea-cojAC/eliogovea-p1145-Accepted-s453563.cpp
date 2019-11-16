#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,a;
double l[1000],m;
string s;

int main(){
    cin >> n;
    while(n--){
               cin >> a;
               for(int i=0; i<a; i++)cin >> s >> l[i];
               
               sort(l,l+a);
               
               m=360-(l[a-1]-l[0]);
               
               for(int i=1; i<a; i++)if(m<l[i]-l[i-1])m=l[i]-l[i-1];
               
               m=12.0*(360.0-m);
               
               if(m-int(m) >= 0.5)m=ceil(m);
               else m=floor(m);
               
               cout << m << endl;
               }
    }
