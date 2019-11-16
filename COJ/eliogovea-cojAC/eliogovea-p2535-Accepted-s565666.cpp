#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int MAXL = 510;

int k;
string word;
bool dp[MAXL][MAXL];
map<string,int> M;
map<string,int>::iterator it;

int main(){

    cin >> k >> word;

    for( int i = 0; i < word.size(); i++ ) dp[i][i] = 1;
    for( int i = 0; i < word.size() - 1; i++ ) dp[i][i + 1] = word[i] == word[i + 1];
    for( int l = 2; l <= word.size(); l++ )
        for( int i = 0; i + l <= word.size(); i++ )
            dp[i][i + l] = ( word[i] == word[i + l] && dp[i + 1][i + l - 1] );

    for( int i = 0; i < word.size(); i++ )
        for( int j = i + 1; j < word.size(); j++ )
            if( dp[i][j] )
            {
                string aux = "";
                bool b = false;
                for( int k = i; k <= j; k++ )
                {
                    if( k < j && dp[i][k] && dp[k + 1][j] ) b = true;
                    aux += word[k];
                }
                if( b ) M[aux]++;
                ///cout << aux << " " << M[aux] << endl;
            }
    int mx = 0;
    string sol = "-";
    bool b = false;
    for( it = M.begin();it != M.end(); it++ )
        if( it->first.size() >= k )
        {
            if( it->second > mx )
            {
                mx = it->second;
                sol = it->first;
            }
            else if( it->second == mx && sol < it->first )
                sol = it->first;
        }

    if( sol == "-" )cout << sol << endl;
    else cout << sol << " " << mx << endl;
    return 0;
}
