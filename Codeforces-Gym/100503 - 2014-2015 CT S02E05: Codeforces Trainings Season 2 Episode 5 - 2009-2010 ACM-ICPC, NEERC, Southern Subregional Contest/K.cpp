// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503K

#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-5;
const string OpenReg  = "<ul>",
             CloseReg = "</ul>",
             OpenEnum = "<ol>",
             CloseEnum= "</ol>",
             OpenItem = "<li>",
             CloseItem= "</li>";
int n = 0;
string sol;
string line[10000];
void solve( int ini, int fin, int cur ){
    if( ini == fin ){
        sol += OpenItem + "\n";
        sol += line[ini].substr( cur, line[ini].size()-cur );
        sol += CloseItem + "\n";
    }
    else{
        for( int i = ini; i <= fin; ){
            sol += OpenItem + "\n";
            int l = 0;
            if( line[i][cur] != '*' && line[i][cur] != '#' ){
                sol += line[i].substr( cur, line[i].size()-cur ) + "\n";
            }
            else{

                while( line[i][cur] == line[i+l][cur] && i+l <= fin )
                    l++;
                l--;
                if( l == 0 ){
                    sol += line[i].substr( cur, line[i].size()-cur ) + "\n";
                }
                else{
                    if( line[i][cur] == '*' )
                        sol += OpenReg + "\n";
                    else
                        sol += OpenEnum + "\n";

                    solve( i, i+l, cur+1 );
                    if( line[i][cur] == '*' )
                        sol += CloseReg + "\n";
                    else
                        sol += CloseEnum + "\n";
                }
            }
            i+= l+1;
            sol += CloseItem + "\n";
        }

    }

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    while( cin >> line[++n] );

    for( int i = 1; i <= n; ){
        if( line[i][0] != '*' && line[i][0] != '#' ){
            sol += line[i];
            sol += "\n";
            i++;
            continue;
        }
        int l = 0;
        while( line[i][0] == line[i+l][0] && i+l <= n )
            l++;
        l--;

        if( l > 0 ){
            if( line[i][0] == '*' )
                sol += OpenReg + "\n";
            else
                sol += OpenEnum + "\n";
            //cout << "solve: " << i << " " << i+l << endl;
            solve( i, i+l, 1 );

            if( line[i][0] == '*' )
                sol += CloseReg + "\n";
            else
                sol += CloseEnum + "\n";

        }
        else{
            sol += line[i] + "\n";
        }
        i += l+1;
    }
    cout << sol << '\n';

}

