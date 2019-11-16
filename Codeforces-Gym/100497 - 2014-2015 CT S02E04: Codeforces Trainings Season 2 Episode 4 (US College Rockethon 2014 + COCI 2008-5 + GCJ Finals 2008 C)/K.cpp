// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000000;

vector<int> g[MAXN];
int d[MAXN];

int cola[MAXN];
bool mk[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    string l;

    map<string,int> dic;

    int n = 0;

    //leer
    while( cin >> l ){
        if( dic.find(l) == dic.end() ){
            dic[l] = ++n;
        }

        int v = dic[l];
        mk[v] = true;

        //cout << l;

        while( cin >> l, l != "0" ){
            if( dic.find(l) == dic.end() ){
                dic[l] = ++n;
            }

            //cout << ' ' << l;

            int u = dic[l];

            g[u].push_back( v );
            d[v]++;
        }

//        cout << '\n';
    }

    int enq = 0, deq = 0;

    int sol = 0;

    for( int i = 1; i <= n; i++ ){
        if( d[i] == 0 && mk[i] ){
            cola[enq++] = i;
            sol++;
        }
    }

   // cout << sol << '\n';

    while( enq - deq ){
        int u = cola[deq++];
        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];

            if( d[v] ){
                d[v]--;
                if( d[v] == 0 ){
                    sol++;
                    cola[enq++] = v;
                }
            }
        }
    }

    cout << sol << '\n';
}
