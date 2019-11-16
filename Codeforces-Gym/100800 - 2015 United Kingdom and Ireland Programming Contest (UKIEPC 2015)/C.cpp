// 2015 United Kingdom and Ireland Programming Contest (UKIEPC 2015)
// 100800C

#include <bits/stdc++.h>

using namespace std;
int n;
map<string, set<string> > m;
map<string, set<string> >::iterator it;
map<string,int> freq;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	///freopen("dat.txt", "r", stdin);

    cin >> n;
    //cout << n << endl;
    getline( cin, s );
    for( int i = 0; i < n; i++ ){
        getline( cin, s );
        istringstream li( s );
        string user;
        li >> user;
        m[user];
        it = m.find( user );
        while( li >> s ){
            freq[s]++;
            it->second.insert( s );
        }
    }
    map<string, int> cnt;
    for( it = m.begin(); it != m.end(); it++ ){
        set<string>::iterator i;
        for( i = it->second.begin(); i != it->second.end(); i++ ){
            cnt[*i]++;
        }
    }
    map<string, int>::iterator ii;

    vector< pair<int,string> > v;
    for( ii = cnt.begin(); ii != cnt.end(); ii++ ){
        if(ii->second == m.size() )
            v.push_back( make_pair( -freq[ii->first], ii->first ) );
    }
    sort( v.begin(), v.end() );
    for( vector< pair<int,string> >::iterator i = v.begin(); i != v.end(); i++ )
        cout << i->second << '\n';
    if( !v.size() )
        cout << "ALL CLEAR\n";

}
