#include<iostream>
using namespace std;

struct pto{
       int x,y,z;
       };
       
int n;
pto p1,p2,p3;

bool al(pto a, pto b, pto c){
     int x1 = b.x-a.x;
     int x2 = c.x-a.x;
     int y1 = b.y-a.y;
     int y2 = c.y-a.y;
     int z1 = b.z-a.z;
     int z2 = c.z-a.z;
     
     return (y1*z2-z1*y2) || (z1*x2-x1*z2) || (x1*y2-y1*x2);
     }
     
int main(){
    
    cin >> n;
    while(n--){
               cin >> p1.x >> p1.y >> p1.z >> p2.x >> p2.y >> p2.z >> p3.x >> p3.y >> p3.z;
               if(al(p1,p2,p3))cout << "YES" << endl;
               else cout << "NO" << endl;
               }
    return 0;    
    }
