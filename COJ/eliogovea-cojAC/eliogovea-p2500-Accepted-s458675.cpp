#include<iostream>
using namespace std;

char c1,c2,ca,cb;
int x,y,x1,x2,y1,y2,n;

int main(){
    cin >> n;
    while(n--){
               cin >> c1 >> y1 >> c2 >> y2;
               x1=c1-'A'+1;
               x2=c2-'A'+1;
               if((x1+y1)%2 != (x2+y2)%2)cout << "Impossible\n";
               else if(x1==x2 && y1==y2)cout << "0 " << c1 << " " << y1 << endl;
               else if((x1-y1==x2-y2) || (x1+y1==x2+y2))cout << "1 " << c1 << " " << y1 << " " << c2 << " " << y2 << endl;
               else{
                    x=(x1+y1+x2-y2)/2;
                    y=(x1+y1-x2+y2)/2;
                    ca='A'+x-1;
                    if(x>0 && x<9 && y>0 && y<9)cout << "2 " << c1 << " " << y1 << " " << ca << " " << y << " " << c2 << " " << y2  << endl;
                    else{
                         x=(x1-y1+x2+y2)/2;
                         y=(y1-x1+x2+y2)/2;
                         ca='A'+x-1;
                         if(x>0 && x<9 && y>0 && y<9)cout << "2 " << c1 << " " << y1 << " " << ca << " " << y << " " << c2 << " " << y2 << endl;
                         }
                    }
               }
    return 0;
    }
