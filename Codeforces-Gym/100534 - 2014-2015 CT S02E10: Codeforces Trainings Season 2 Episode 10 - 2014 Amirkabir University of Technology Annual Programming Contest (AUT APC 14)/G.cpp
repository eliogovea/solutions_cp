// 2014-2015 CT S02E10: Codeforces Trainings Season 2 Episode 10 - 2014 Amirkabir University of Technology Annual Programming Contest (AUT APC 14)
// 100534G

#include<bits/stdc++.h>
#define MAXN 500000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> par;

string str,str2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "data.txt", "r", stdin );
    cin >> str;
    str2 = str;
    int p = 0;
    int acc1 =  0, acc2 = 0;

    for( int i = 0; i < str.size(); i++ ){
        if( str[i] == '2' ){
            acc1 += i-p;
            p++;
        }
    }

    p = 0;
    for( int i = 0; i < str.size(); i++ ){
        if( str[i] == '1' ){
            acc2 += i-p;
            p++;
        }
    }

    cout << min(acc1,acc2) << '\n';

}

