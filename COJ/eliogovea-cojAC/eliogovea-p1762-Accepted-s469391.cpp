#include<iostream>
#include<cstring>
using namespace std;

char a[30],b[30];
int pa,pb;

int main(){
    cin >> a >> b;
    int la=strlen(a),lb=strlen(b);
    for(int i=la-1; i>=0; i--)
    for(int j=lb-1; j>=0; j--)if(a[i]==b[j]){pa=i;pb=j;}
    for(int i=0; i<lb; i++){
            for(int j=0; j<la; j++){
                    if(j==pa)cout << b[i];
                    else if(i==pb)cout << a[j];
                    else cout << '.';
                    }
            cout << endl;
            }
    return 0;
    }
