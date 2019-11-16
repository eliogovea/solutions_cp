#include<iostream>
using namespace std;

struct pto{
       int x,y;
       };
       
bool no_al(pto a, pto b, pto c){
     int x1 = b.x-a.x;
     int x2 = c.x-a.x;
     int y1 = b.y-a.y;
     int y2 = c.y-a.y;
     
     return x1*y2-y1*x2;
     }

pto p[130];
int c,n,k,tc;

int main(){
    cin >> tc;
    while(tc--){
                cin >> n; n++;
                c=0;k=0;
                for(int i=0; i<n; i++)
                for(int j=0; j<n; j++){p[k].x=i;p[k].y=j;k++;}
                
                for(int i=0; i<k-2; i++)
                for(int j=i+1; j<k-1; j++)
                for(int l=j+1; l<k; l++)if(no_al(p[i],p[j],p[l]))c++;
                
                cout << c << endl;
                }
    return 0;
    }
