#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct nodo{
       int x,y;
       }l[102];

queue<nodo> q;

int c,n;
bool b[102];

int main(){
    cin >> c;
    while(c--){
               cin >> n;
               for(int i=0; i<n+2; i++){
                       cin >> l[i].x >> l[i].y;
                       b[i]=0;
                       }

               q.push(l[0]);
               b[0]=1;

               bool f=1;
               while(!q.empty()){
                                 int xx=q.front().x;
                                 int yy=q.front().y;

                                 q.pop();

                                 if(abs(xx-l[n+1].x)+abs(yy-l[n+1].y)<=1000){f=0;break;}

                                 for(int i=1; i<n+1; i++)
                                 if(abs(xx-l[i].x)+abs(yy-l[i].y)<=1000 && !b[i]){q.push(l[i]);b[i]=1;}
                                 }

               if(f)cout << "sad" << endl;
               else cout << "happy" << endl;

               while( !q.empty() )q.pop();
               }
    return 0;
    }
