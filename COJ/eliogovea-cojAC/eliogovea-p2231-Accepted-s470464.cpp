#include<iostream>
#include<string>
using namespace std;

string s1,s2;
int n,p1,p2;
int  main(){
     cin >> n;
     while(n--){
                cin >> s1 >> s2;
                //if(s1==s2){p1++;p2++;}
                if(s1=="rock" && s2=="scissors")p1++;
                else if(s2=="rock" && s1=="scissors")p2++;
                else if(s1=="scissors" && s2=="paper")p1++;
                else if(s2=="scissors" && s1=="paper")p2++;
                else if(s1=="paper" && s2=="rock")p1++;
                else if(s2=="paper" && s1=="rock")p2++;
                }
     if(p1>p2)cout << "A win";
     else if(p1<p2)cout << "B win";
     else cout << "tied";
     return 0;
     }