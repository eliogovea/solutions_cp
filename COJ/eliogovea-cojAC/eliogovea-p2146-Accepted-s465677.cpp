#include<iostream>
using namespace std;

unsigned long long v,d;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> d >> v;
    if(d==(v*(v-1))/2-v)cout << "yes"<< endl;
    else cout << "no" << endl;
    return 0;
    }
