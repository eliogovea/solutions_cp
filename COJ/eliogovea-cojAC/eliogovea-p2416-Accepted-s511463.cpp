#include<iostream>
using namespace std;

int c,n;

int s(int a){
    int t=0;
    while(a){
             t+=a%10;
             a/=10;
             }
    return t;
    }

int main(){
    cin >> c;
    while(c--){
               cin >> n;
			   cout << 9-n%9 << endl;
    }
	return 0;
}
