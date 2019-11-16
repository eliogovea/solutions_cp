#include<iostream>
using namespace std;
int m(int a, int b){
    return a>b?a:b;
    }
    
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
            int MAX=0;
            int  n1;
            cin >> n1;
            int t[n1][n1];
            for(int j=0; j<n1; j++){
                    for(int k=0; k<=j; k++){
                            cin >> t[j][k];
                            }
                    }
            int t1[n1][n1];
            t1[0][0]=t[0][0];
            for(int j=1; j<n1; j++){
                    t1[j][0]=t[j][0]+t1[j-1][0];
                    t1[j][j]=t[j][j]+t1[j-1][j-1];
                    }
            for(int j=2; j<n1; j++)
            for(int k=1; k<j; k++){
                    t1[j][k]=t[j][k]+(m(t1[j-1][k-1],t1[j-1][k]));
                    }
            for(int ii=0; ii<n1; ii++){
                    if(t1[n1-1][ii]>MAX)MAX=t1[n1-1][ii];
                    }
            cout << MAX << endl;
            }
    }