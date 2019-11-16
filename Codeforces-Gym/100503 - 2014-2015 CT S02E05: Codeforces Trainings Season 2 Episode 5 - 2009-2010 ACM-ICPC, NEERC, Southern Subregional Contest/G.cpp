// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503G

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
	cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> s;
        int len = s.size();
        if( ( s[len-2]=='c' && s[len-1] == 'h' ) || s[len-1] =='x' || s[len-1]=='s' || s[len-1] == 'o' ){
            cout << s << "es\n";
        }
        else if( s[len-1]=='f' ){
            s[len-1] = 'v';
            cout << s << "es\n";
        }
        else if( s[len-2] == 'f' && s[len-1] == 'e' ){
            s[len-2] = 'v';
            cout << s << "s\n";
        }
        else if( s[len-1] == 'y' ){
            s[len-1] = 'i';
            cout << s << "es\n";

        }
        else{
            cout << s << "s\n";
        }


    }

}

