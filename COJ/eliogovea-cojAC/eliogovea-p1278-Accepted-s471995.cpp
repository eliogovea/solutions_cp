#include<iostream>
#include<algorithm>
using namespace std;

int a[6];
double s;

int main(){
    while(1){
             s=0;
             bool b=0;
             for(int i=0; i<6; i++){cin >> a[i];if(a[i]!=0)b=1;}
             if(!b)break;
             sort(a,a+6);
             for(int i=1; i<5; i++)s+=double(a[i]);
             s/=4.0;
             cout << s << endl;
             }
    return 0;
    }

