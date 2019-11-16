#include<iostream>
using namespace std;

float rec[10][4],x,y;
char c;
int k,i=1;

int main(){
    while(cin >> c && c!='*'){
              cin >> rec[k][0] >> rec[k][1] >> rec[k][2] >> rec[k][3];
              k++;
              }
    while(cin >> x >> y){
              if(x==9999.9f && y==9999.9f)break;
              bool b=1;
              for(int j=0; j<k; j++)if(x>rec[j][0] && x<rec[j][2] && y<rec[j][1] && y>rec[j][3]){
                      cout << "Point " << i <<  " is contained in figure " << j+1 << endl;
                      b=0;
                      }              
              if(b)cout << "Point " << i << " is not contained in any figure" << endl;
              i++;
              }
    return 0;
    }
