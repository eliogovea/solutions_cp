#include<iostream>
using namespace std;

int n;
long long t,p[100000][2],x[100001],y[100001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> p[i][0] >> p[i][1];
            x[p[i][0]]++;
            y[p[i][1]]++;
            }
    for(int i=0; i<n; i++){
            if(x[p[i][0]]>1 && y[p[i][1]]>1)t+=(x[p[i][0]]-1)*(y[p[i][1]]-1);
            }
    cout << t << endl;
    return 0;
    }
