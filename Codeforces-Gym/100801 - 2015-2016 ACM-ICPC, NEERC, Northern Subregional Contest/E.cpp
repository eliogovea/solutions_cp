// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;

string str, num;
string proc(string &a ){
    string res = "";

    //cout << "debug:\n";
    //cout << a << endl;
    if( a.size() == 1 )
        return a;
    for( int i = 0; i < a.size(); i++ ){
        res += a[i];
        if( i+1 < a.size() ){
            res += '+';
            if(  a[i+1] != '0' ){
                res += a.substr( i+1, a.size()-i-1 );
                break;
            }
        }

    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);

    cin >> str;
    for( int i = 0; i < str.size(); i++ ){
        if( str[i] != '-' ){
            cout << str[i];
            //cout << "j";
            continue;
        }
        cout << "-";
        int x = i+1;
        num = "";
        while( isdigit(str[x]) && x < str.size() ){
            num += str[x];
            x++;
        }
        i = x-1;
        cout << proc( num );


    }
    cout << "\n";
}
